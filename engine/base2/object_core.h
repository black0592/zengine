// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
//  �ο�mfc��log4cxxʵ�ֵ�������JAVA�Ķ���ģ��
//  ��л����� J.J.Hou (jjhou),  jjhou@jjhou.com,  www.jjhou.com
//  �ṩ�ģ�MFCLite 3.5��һ�������΢�� MFC-like application framework
//

/*
	MFC�Ķ���ģ��ֻ�ṩ�����̳У�
	����

	class A : 
		public Object {
		DECLARE_DYNAMIC(A)
	public:
		virtual ~A() {}
	};

	IMPLEMENT_DYNAMIC(A, Object)

	class AImpl :
		public virtual A {
		DECLARE_DYNAMIC(AImpl)
	public:
		virtual ~AImpl() {}
	};

	IMPLEMENT_DYNAMIC(AImpl, A)

	class BA :
		public virtual A {
		DECLARE_DYNAMIC(BA)

	public:
		virtual ~BA() {}

	};

	IMPLEMENT_DYNAMIC(BA, A)

	class BAImpl :
		public AImpl,
		public BA {

		DECLARE_DYNCREATE(BAImpl)

	public:

	};

	IMPLEMENT_DYNAMIC(BAImpl, AImpl)

	������Ķ���ģ��ִ���������䣺
	std::cout << impl->IsKindOf(RUNTIME_CLASS(BA)) << std::endl; // 0
	std::cout << impl->IsKindOf(RUNTIME_CLASS(AImpl)) << std::endl; // 1

	�������Ķ���ģ�Ͳ����������ǵ�������Ҫ�޸ġ�


	//����MFC�����ϸĻ�����log4cxx�������޸ģ�������
	//��log4cxxû����Ĺ�ϵ��Ϣ
	//���ܻ���ʹ��log4cxx������һЩ����
	//	Ҳ�����ã�MFC��ʵ��Ҳ�ܲ���ģ�MFC��CLASS֮��Ĺ�ϵͨ��һ����������֮��Ĺ�ϵά��������
	//	ֻҪʹ�����ṹ��ά��������ôҲ��ʵ�����ǵ������ˡ����ǿ��Զ����һЩ�꣬��ô
	//  ʵ��getSuperClass,getInterfaces�ȶ�����ʵ��
	//  �ڴ˶���ģ�������ǿ��Զ���һЩ����ָ����Щ������JAVA���Interfaces....
 */

#ifndef BASE2_OBJECT_CORE_H_
#define BASE2_OBJECT_CORE_H_

#include <cstdio>    // for FILE*, NULL (0)
#include <string>    //5 ��춙n��, IDR_
#include <map>

////////// ǰ�����棨forward declaration��/////////////////////
////////// e�A���wϵ��classes hierarchy��///////////////////
class Object;
struct Class;


////////// Class �� MFCLite ���A���O֮���� /////////////
////////////////////////////////////////////////////////////////
struct Class
{
	typedef Object* (* FuncNewObject)();

	//���ǼӸ����캯����
	//�������Ϊ��9����̳�
	Class();
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7, Class* baseNextClass8);
	Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7, Class* baseNextClass8, Class* baseNextClass9);

	char* class_name_;  // class ���Q
	int object_size_;      // object ��С
	unsigned int schema_;         // �汾��̖��schema number��

	Object* (* newObject_)();  // ָ��һ����ʽ�������w�� 'new Cxxx';
	// �@�ǂ� pointer to non-member function, ��֮���Կ��Á�����T��
	// &CFoo::CreateObject �@�ӵĖ|�����������Ҳ�� ptr to non-member funcion��
	// ����������ǂ� static ��ʽ����ֻ���^ò�� ptr to member function �T�ˡ�
	// Ҋ pic2\prog\pmftest2.cpp

	Class* base_;				// ָ�� base������ģ�Mtree����һ�����ڵ�
	Class* base_next_;			// �������ڵ�

	Class* next_;		// �Ժ��ε� linked list����  ���е� Class objects ���B����

	static Class* first_; // ��ʼ���c��ֻ��һ�ݣ����Ԟ� static��

	// for Dynamic Creation���ӑB���ɣ�
	Object* newInstance() const;
	// ����磨���� Class object �ߣ�������У��Ա�a������֮ object��
	// ���䌍���ǆ��� (*m_pfnCreateObject)()��Ҋ mfclite.cpp���������ֆ���
	// Cxxx::CreateObject()������ 'new Cxxx'��
	// ��Ҫ���@�� Class::CreateObject() �� Cxxx::CreateObject() ������
	// ǰ�ߞ� non-static�����ߞ� static��ǰ�ߺ������ߡ�

	//mfc9��������
	bool derivedFrom(const Class* baseClass) const;

	std::string toString() const;
	std::string getName() const{ return class_name_; };
	static Class* forName(const char* className);
	static Class* forName(const std::string& className);
	static Object* newInstance(const char* className);
	static Object* newInstance(const std::string& className);

};

// �����OӋ���Ǟ��������ÿ�� classes ����һ���`��ԓ�̈́e�� global object��
// ����� global object�������� ctor ����� main() ���У�
// ��������� main() ֮ǰ�O�ú� Class objects ���B�ġ�e��䛾W����
// ԔҊ _IMPLEMENT_RUNTIMECLASS macro.
struct AFX_CLASSINIT
       { AFX_CLASSINIT(Class* newClass); };   // ctor

// �����OӋ���Ǟ��ˌ�����ȡ�á�e��䛾W���е�ĳ�� Class object
#define RUNTIME_CLASS(class_name) \
        (&class_name::class##class_name)

// DECLARE_, level1
// �����O���� static�����ֻ��һ�ݡ�
#define DECLARE_DYNAMIC(class_name) \
public: \
  static Class class##class_name; \
  virtual Class* getClass() const;  // (A)

// DECLARE_, level2�����w level1
// ���� (B) �O���� static����ϣ��δ���κ� object �r�Ϳɺ���֮
#define DECLARE_DYNCREATE(class_name) \
  DECLARE_DYNAMIC(class_name) \
  static Object* newInstance();  // (B).
  // (B) �ĺ�ʽ���wֻ�� 'new Cxxx'; ��ԔҊ IMPLEMENT_DYNCREATE��
  // (B) λַ�����O�o Class::m_pfnCreateObject��Ҋ _IMPLEMENT_RUNTIMECLASS��
  // (B) ���c��� virtual ctor���༴ factory method��������ȫ�ǡ�
  //     factory method ���a����ͬ�̈́e�� object���@�e�� CreateObject() ֻ��
  //     �a���ض��ģ��༴���� class���� object��
  // (B) ��Ҫ�� Class::CreateObject() �����ˡ�ǰ����K�����е��@�e��
  //       Ҋ mfclite.cpp

// IMPLEMENT_, level0���Ȳ��������⹫�_����һ���޼�
// ע�⣬���޼�չ�_��ĽY��������¶� global scope �С�
// ���� static ������O�� file scope����ʹ�����ڙn�����ع�
#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
  static char _lpsz##class_name[] = #class_name; \
  Class class_name::class##class_name(_lpsz##class_name, sizeof(class_name), wSchema, pfnNew, RUNTIME_CLASS(base_class_name)); \
  static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
  Class* class_name::getClass() const \
          { return &class_name::class##class_name; }

#define _IMPLEMENT_RUNTIMECLASS2(class_name, base_class_name, base_class_name2, wSchema, pfnNew) \
  static char _lpsz##class_name[] = #class_name; \
  Class class_name::class##class_name(_lpsz##class_name, sizeof(class_name), wSchema, pfnNew, RUNTIME_CLASS(base_class_name), RUNTIME_CLASS(base_class_name2)); \
  static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
  Class* class_name::getClass() const \
          { return &class_name::class##class_name; }

// ���� level1~level3����ʲ�N��ʹ���� DECLARE_ ��ӌӺ��w���ַ���
// �𰸣����x�ϵĴ_�ǌӌӺ��w�������ӌ�� _IMPLEMENT_RUNTIMECLASS
// ������ɂ��������O��������ͬ�������ַ��Ю���

// IMPLEMENT_, level1����� RTTI��
// ע�⣬�汾��̖�O�� -1�����ɺ�ʽ�� NULL��
#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
  _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, \
                          0xFFFF, NULL)

#define IMPLEMENT_DYNAMIC2(class_name, base_class_name, base_class_name2) \
  _IMPLEMENT_RUNTIMECLASS2(class_name, base_class_name, base_class_name2, \
                          0xFFFF, NULL)

// IMPLEMENT_, level2����� Dynamic Creation��
// ע�⣬�汾��̖�O�� -1�����ɺ�ʽ�� non-NULL��
#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
  Object* class_name::newInstance() \
          { return /*reinterpret_cast<Object*>*/(new class_name); } \
  _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, \
                          0xFFFF, class_name::newInstance)

#define IMPLEMENT_DYNCREATE2(class_name, base_class_name, base_class_name2) \
  Object* class_name::newInstance() \
          { return /*reinterpret_cast<Object*>*/(new class_name); } \
  _IMPLEMENT_RUNTIMECLASS2(class_name, base_class_name, base_class_name2, \
                          0xFFFF, class_name::newInstance)

// Object ��ʹ�� DECLARE_DYNAMIC ϵ�о޼����������֪�������
// ������ IMPLEMENT_DYNAMIC ϵ�о޼���ָ�� base class�����
// ָ���� base class �� null���tչ�_�Y���е� RUNTIME_CLASS(null) ���І��}��
// ��ˣ�Object ����������������֮ Class �������c�O����
// �Լ�������֮ GetRuntimeClass() ������Ͷ��x��
// ref. afx.h
class Object
{
public:
	Object() { }
	virtual ~Object() { }  // virtual dtor is necessary

	//for JAVA�ӿ�
	virtual Class* getClass() const;
	bool instanceof(const Class* clazz) const;
	//virtual const void * cast(const Class* clazz) const;
	//add by wubenqi
	virtual std::string getName() { return getClass()->class_name_;}

	//�ο�log4cxx�����һ��cast���⺯��
	//virtual const Object* cast(const Class* clazz) const;

	virtual Object* Clone();
	
public:
	static Class classObject; // ֻҪһ�ݾͺá�
};

#endif // __object_core_H__

