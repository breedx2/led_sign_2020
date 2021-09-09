
let isDragging = false;

function ledClicked(col, row){
  console.log(`saw sweet click: ${col}, ${row}`)
}

function setNotDragging(){
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

function clearClicked(){
  clearSign();
}

function pencilClicked(){
  toggleWidge('pencilbutton');
  const eraser = document.getElementById('erasebutton');
  eraser.classList.remove('btn-success');
  eraser.classList.add('btn-secondary');
}

function eraserClicked(){
  toggleWidge('erasebutton');
  const pencil = document.getElementById('pencilbutton');
  pencil.classList.remove('btn-success');
  pencil.classList.add('btn-secondary');
}

function toggleWidge(id){
  const pencil = document.getElementById(id);
  if(pencil.classList.contains('btn-success')){
    disableWidge(id);
  }
  else{
    enableWidge(id);
  }
}

function enableWidge(id){
  const elem = document.getElementById(id);
  elem.classList.add('btn-success');
  elem.classList.remove('btn-secondary');
}

function disableWidge(id){
  const elem = document.getElementById(id);
  elem.classList.remove('btn-success');
  elem.classList.add('btn-secondary');
}
