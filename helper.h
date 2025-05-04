#ifndef PARSECONFIG
#define PARSECONFIG
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sodium.h>

std::map<std::string,std::map<std::string, std::string>> loadIniConfig(const std::string& filename){
 std::string line,section;
 std::ifstream file(filename);
 std::map<std::string,std::map<std::string, std::string>> config;
 
 if (!file.is_open()){
  std::cerr << "Error Opening File: " << filename<< std::endl; 
  return config;
 }

 
 while(std::getline(file,line)){
  
  line.erase(0,line.find_first_not_of(" \t\r\n"));
  line.erase(line.find_last_not_of(" \t\r\n")+1);
  
  if (line.empty() || line.front() == ';' || line.front() == '#') continue;
  
  if (line.front() == '[' && line.back() == ']') {
   section = line.substr(1,line.size()-2);

   continue;
   
  };
  
  auto pos = line.find('=');
  if (pos == std::string::npos) continue;
  
  std::string key = line.substr(0,pos);
  std::string value = line.substr(pos + 1);

  
  key.erase(0,key.find_first_not_of(" \t\r\n"));
  key.erase(key.find_last_not_of(" \t\r\n")+1);
  value.erase(0,value.find_first_not_of(" \t\r\n"));
  value.erase(value.find_last_not_of(" \t\r\n")+1);

  
  config[section][key] = value;
  
 }
 return config;
}

std::string hashPassword(const std::string& password){
 char hashed[crypto_pwhash_STRBYTES];
 if(crypto_pwhash_str(
  hashed,
  password.c_str(),
  password.length(),
  crypto_pwhash_OPSLIMIT_INTERACTIVE,
  crypto_pwhash_MEMLIMIT_INTERACTIVE)!=0){
  
  std::cerr << "Out of memory." << std::endl;
   return 0;
  }
  return std::string(hashed);
}
bool isValid;
bool validatePassword(const std::string hashed,std::string epassword){

 if (crypto_pwhash_str_verify(hashed.c_str(),epassword.c_str(),epassword.length()) == 0){
  isValid = true;
 }else {
  isValid = false;
 }
 return isValid;
}


#endif


