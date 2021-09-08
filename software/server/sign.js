'use strict';

class Sign {

  constructor(){
    this.online = false;
    this.lastUpdate = '';
    this.content = [];
  }

  isOnline(){
    return this.online;
  }

  isOffline(){
    return !this.offline;
  }

  setOnline(status){
    this.online = status;
  }

  getLastUpdate(){
    return this.lastUpdate;
  }

  setLastUpdate(lastUpdate){
    this.lastUpdate = lastUpdate;
  }

  setContent(content){
    this.content = content;
  }

  getContent(){
    return this.content;
  }

}


module.exports = Sign;
