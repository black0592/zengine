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

#include "base2/object_core.h"

#include <functional>  // modulus<>()
#include "base/logging.h"
#include "base/string_util.h"

using namespace std;


//////////// Class Implementation //////////////////////
////////////////////////////////////////////////////////////////

// Object ��Ȼ�����܉��� macro �{�롸e��䛾W�����͵��ք���ɡ�
// ref. objcore.cpp
static char szObject[] = "Object";
struct Class Object::classObject;

static AFX_CLASSINIT _init_Object(&Object::classObject);

// ����e��䛾W�����^���O���׮�
Class* Class::first_ = NULL;

AFX_CLASSINIT::AFX_CLASSINIT(Class* newClass)
// �˽���ʽؓ؟�������S�M��e��䛾W�����ǂ�����
{
  newClass->next_ = Class::first_;
  Class::first_ = newClass;
}

//struct Class Object::classObject =
//{ szObject, sizeof(Object), 0xFFFF, NULL, NULL, NULL, NULL };
Class::Class()
{
	class_name_ = szObject;
	object_size_ = sizeof(Object);
	schema_ =  0xFFFF;
	newObject_ = NULL;
	base_ = NULL;
	base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = baseNextClass5;
	baseNextClass5->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = baseNextClass5;
	baseNextClass5->base_next_ = baseNextClass6;
	baseNextClass6->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = baseNextClass5;
	baseNextClass5->base_next_ = baseNextClass6;
	baseNextClass6->base_next_ = baseNextClass7;
	baseNextClass7->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7, Class* baseNextClass8)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	base_next_ = baseNextClass1;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = baseNextClass5;
	baseNextClass5->base_next_ = baseNextClass6;
	baseNextClass6->base_next_ = baseNextClass7;
	baseNextClass7->base_next_ = baseNextClass8;
	baseNextClass8->base_next_ = NULL;
	next_ = NULL;
}

Class::Class(char* className, int objectSize, int schema, FuncNewObject fnNew, Class* baseClass, Class* baseNextClass1, Class* baseNextClass2, Class* baseNextClass3, Class* baseNextClass4, Class* baseNextClass5, Class* baseNextClass6, Class* baseNextClass7, Class* baseNextClass8, Class* baseNextClass9)
{
	class_name_ = className;
	object_size_ = objectSize;
	schema_ =  schema;
	newObject_ = fnNew;
	base_ = baseClass;
	baseNextClass1->base_next_ = baseNextClass2;
	baseNextClass2->base_next_ = baseNextClass3;
	baseNextClass3->base_next_ = baseNextClass4;
	baseNextClass4->base_next_ = baseNextClass5;
	baseNextClass5->base_next_ = baseNextClass6;
	baseNextClass6->base_next_ = baseNextClass7;
	baseNextClass7->base_next_ = baseNextClass8;
	baseNextClass8->base_next_ = baseNextClass9;
	baseNextClass9->base_next_ = NULL;
	next_ = NULL;
}


// ref. objcore.cpp
Object* Class::newInstance() const
{
  // ���� Class���a��һ�������� object��
  if (newObject_ == NULL)
  {
	  //DLOG(ERROR) << "Error: class not DECLARE_DYNCREATE or \nDECLARE_SERIAL : "
			//		<< class_name_;
      return NULL;
  }

  Object* pObject = NULL;           // �����U�����O�� null
  pObject = (*newObject_)();  // EC++ �l��7��ӛ���w����r�G�� std::bad_allc
                                     // Ҳ������������ 0���������⌑����
  return pObject;
}


//����nextClass????
bool Class::derivedFrom(const Class* baseClass) const
{
	//DCHECK(this != NULL);
	//DCHECK(baseClass != NULL);

	const Class* classThis = this;
	while (classThis != NULL)
	{
		if (classThis == baseClass)
			return true;
		classThis = classThis->base_;
	}
	return false;       // walked to the top, no match

}

Class* Class::forName(const char* className) 
{
	Class* clazz=NULL;

	//DCHECK(className!=NULL);

	// search app specific classes
	//todo�Ƿ���Ҫͬ��������
	//����Ҫͬ����
	//AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	//AfxLockGlobals(CRIT_RUNTIMECLASSLIST);
	for (clazz = first_; clazz != NULL; clazz = clazz->next_) {
		if (base::strcasecmp(className, clazz->class_name_) == 0) {
			//AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);
			return clazz;
		}
	}
	//AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);
	return NULL; // not found
}

Class* Class::forName(const std::string& className)
{
	return forName(className.c_str());
}

Object* Class::newInstance(const char* className)
{
	//DCHECK(className);

	// attempt to find matching runtime class structure
	Class* pClass = forName(className);
	if (pClass == NULL)
	{
		// not found, trace a warning for diagnostic purposes
		//DLOG(ERROR) << "Warning: Cannot find "
		//				<< className
		//				<< " CRuntimeClass.  Class not defined.";
		return NULL;
	}

	// attempt to create the object with the found CRuntimeClass
	Object* pObject = pClass->newInstance();
	return pObject;
}

Object* Class::newInstance(const std::string& className)
{
	return newInstance(className.c_str());
}


//////////// Object Implementation ////////////////////////////
//////////// ref. objcore.cpp //////////////////////////////////

Class* Object::getClass() const
{
	return &Object::classObject;
}

bool IsKindOf(const Class* classThis, const Class* clazz) {
	const Class* pClazz = classThis; 
	// Ȼ����Լ�λ���_ʼ�������߱�������ϵ�������c pClass �Ǻ��ߡ�
	while (classThis != NULL) {
		if (classThis == clazz)
			return true;
		classThis = classThis->base_;
	}

	//û���ҵ������Ƿ����������࣬û���������࣬�򷵻�û�ҵ����еĻ����ݹ����߹���
	if (pClazz->base_next_==NULL) {
		return false;
	}
	return IsKindOf(pClazz->base_next_, clazz);
}

//��MFCLITE��ͬ���ǣ���Ҫʹ�õݹ����
bool Object::instanceof(const Class* clazz) const 
{
	if (clazz==NULL) return false;
	return IsKindOf(getClass(), clazz);
}

Object* Object::Clone() { 
	NOTREACHED() << "Must be Impl Clone function";
	return NULL; 
}


//////////////////////////////////////////////////////////////////////////

