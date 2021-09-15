
let isDragging = false;
let drawMode = false;
let eraseMode = false;

function ledClicked(col, row){
  console.log(`saw sweet click: ${col}, ${row}`)
  if(drawMode){
    ledOn(col, row);
    sendSingleLed(col, row, true);
  }
  else if (eraseMode){
    ledOff(col, row);
    sendSingleLed(col, row, false);
  }
}

function startDragging(){
  if(!drawMode && !eraseMode) return;
  isDragging = true;
}

function setNotDragging(){
  isDragging = false;
}

function ledMouseDown(col, row){
  // console.log(`mouse down ${col} ${row}`)
  if(!drawMode && !eraseMode) return;
  isDragging = true;
  if(drawMode) {
    document.getElementById('signsvg').classList.add('pen');
    document.getElementById('signsvg').classList.remove('eraser');
    ledOn(col, row);
    sendSingleLed(col, row, true);
  }
  else {
    document.getElementById('signsvg').classList.add('eraser');
    document.getElementById('signsvg').classList.remove('pen');
    ledOff(col, row);
    sendSingleLed(col, row, false);
  }
}

function ledMouseUp(col, row){
  console.log(`mouse up ${col} ${row}`)
  isDragging = false;
}

function ledEnter(col, row){
  // console.log(`mouse enter ${col} ${row}`)
  if(isDragging){
    if(drawMode){
      ledOn(col, row);
      sendSingleLed(col, row, true);
    }
    else if(eraseMode){
      ledOff(col, row);
      sendSingleLed(col, row, false);
    }
  }
}

function ledLeave(col, row){
  // console.log(`mouse leave ${col} ${row}`)

}

function clearClicked(){
  clearSign();
  clearRealText();
}

function pencilClicked(){
  drawMode = toggleWidge('pencilbutton');
  disableWidge('erasebutton');
  eraseMode = false;
  if(drawMode){
    document.getElementById('signsvg').classList.add('pen');
  }
  else {
    document.getElementById('signsvg').classList.remove('pen');
  }
  document.getElementById('signsvg').classList.remove('eraser');
  forEveryLed(led => {
    if(drawMode){
      led.classList.add('pen');
    }
    else {
      led.classList.remove('pen');
    }
    led.classList.remove('eraser');
  });
}

function eraserClicked(){
  eraseMode = toggleWidge('erasebutton');
  disableWidge('pencilbutton');
  drawMode = false;
  if(eraseMode){
    document.getElementById('signsvg').classList.add('eraser');
  }
  else {
    document.getElementById('signsvg').classList.remove('eraser');
  }
  document.getElementById('signsvg').classList.remove('pen');
  forEveryLed(led => {
    if(eraseMode){
      led.classList.add('eraser');
    }
    else {
      led.classList.remove('eraser');
    }
    led.classList.remove('pen');
  });

}

function toggleWidge(id){
  if(isWidgeEnabled(id)){
    return disableWidge(id);
  }
  return enableWidge(id);
}

function isWidgeEnabled(id){
  const widge = document.getElementById(id);
  return widge.classList.contains('btn-success');
}

function enableWidge(id){
  const elem = document.getElementById(id);
  elem.classList.add('btn-success');
  elem.classList.remove('btn-secondary');
  return true;
}

function disableWidge(id){
  const elem = document.getElementById(id);
  elem.classList.remove('btn-success');
  elem.classList.add('btn-secondary');
  return false;
}
