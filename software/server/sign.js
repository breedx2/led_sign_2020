'use strict';

class Sign {

  constructor(){
    this.online = false;
    this.lastComms = '';
  }

  isOnline(){
    return this.online;
  }

  isOffline(){
    return !this.offline;
  }

}


module.exports = Sign;
