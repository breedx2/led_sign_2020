
let isDragging = false;

function ledClicked(col, row){
  console.log(`saw sweet click: ${col}, ${row}`)
}

function setNotDragging(){
  console.log('FU thinger');
  isDragging = false;
}

function ledMouseDown(col, row){
  console.log(`mouse down ${col} ${row}`)
  isDragging = true;
  ledOn(col, row);
  sendSingleLed(col, row, true);
}

function ledMouseUp(col, row){
  console.log(`mouse up ${col} ${row}`)
  isDragging = false;
}

function ledEnter(col, row){
  console.log(`mouse enter ${col} ${row}`)
  if(isDragging){
    ledOn(col, row);
    sendSingleLed(col, row, true);
  }
}

function ledLeave(col, row){
  console.log(`mouse leave ${col} ${row}`)

}
