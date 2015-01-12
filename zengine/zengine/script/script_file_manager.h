// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
// Ϊ�˱������ڱ༭�ļ����޸Ļ�ɾ��ʱ���ؽű��ļ����ʲ����ⲿ��������֪ͨ�����¼��ؽű�
// 

#ifndef ZENGINE_SCRIPT_SCRIPT_FILE_MANAGER_H_
#define ZENGINE_SCRIPT_SCRIPT_FILE_MANAGER_H_
#pragma once

#include "base/memory/singleton.h"

#include "base/files/file_path.h"
#include "base/time/time.h"
#include "base2/linked_map.h"

//#include "zengine/zengine_types.h"

class ScriptManager;
class ScriptFileManager {
public:
  static ScriptFileManager* GetInstance() {
    return Singleton<ScriptFileManager>::get();
  }

  struct ScriptFileData {
    ScriptFileData() {
    }

    bool IsModified() {
      return last_modified_time != new_last_modified_time;
    }

    void SetLastModifiedTime(base::Time val) {
      last_modified_time = new_last_modified_time;
      new_last_modified_time = val;
    }

    base::Time last_modified_time;   // �ļ�����޸�ʱ��
    base::Time new_last_modified_time;   // �ļ�����޸�ʱ��
  };

  std::vector<base::FilePath>& GetWatcherFilePaths() {
    return watcher_file_paths_;
  }

  // void RegisterWatcherFilePath(const std::string& file_path);

  void RegisterScriptManager(ScriptManager* script_manager) {
    script_managers_.push_back(script_manager);
  }

  void Initialize(const std::vector<base::FilePath>& file_paths);
  void Destroy();

  // ��ʼ���
  //void DoWatchSignal();

  //// ��Ҫ���¼��صĽű�
  //void OnWatchSignalThreadSafe();

  base::linked_map<base::FilePath, ScriptFileData>& GetScriptDatas() {
    return script_datas_;
  }

private:
  //ScriptFileWatcherThread* watcher_thread_;
  //boost::asio::io_service* io_service_;
  friend struct DefaultSingletonTraits<ScriptFileManager>;

  ScriptFileManager() {
  }

  ~ScriptFileManager() {
    Destroy();
  }

  std::vector<base::FilePath> watcher_file_paths_;
  base::linked_map<base::FilePath, ScriptFileData> script_datas_;

  std::vector<ScriptManager*> script_managers_;
};

#endif
