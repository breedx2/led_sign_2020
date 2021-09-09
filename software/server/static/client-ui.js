
console.log('client ui starting.');
createSignGrid();

const LED_ON_COLOR = '#850c1e';
const LED_OFF_COLOR = '#2e2e2e';

let rescaleTimer;
window.addEventListener('resize', event => {
  if(rescaleTimer){
    clearTimeout(rescaleTimer);
    rescaleTimer = null;
  }
  rescaleTimer = setTimeout(doResize, 250);
});

function doResize(){
  rescaleTimer = null;
  const sign = document.getElementById('sign');

  const led_d = (sign.clientWidth-10)/145.0;
  const led_r = led_d/2;
  const signSvg = document.getElementById('signsvg');
  signSvg.setAttribute('width', sign.clientWidth);
  signSvg.setAttribute('height',(led_d+2) * 7);


  document.querySelectorAll('.oneled').forEach((led,i) => {
    const row = Math.floor(i / 145);
    const col = i % 145;
    led.setAttribute('r', led_r);
    led.setAttribute('cx', led_d*(col+1));
    led.setAttribute('cy', ((row+1)*(led_d))+1);

  });
}

function createSignGrid(){
  const sign = document.getElementById('sign');
  console.log(`sign width = ${sign.clientWidth}`);
  const led_d = (sign.clientWidth-10)/145.0;
  const led_r = led_d/2;

  const signSvg = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
  signSvg.id = 'signsvg';
  signSvg.setAttribute('width', sign.clientWidth);
  signSvg.setAttribute('height',(led_d+2) * 7);
  signSvg.setAttribute('onmouseleave', 'setNotDragging()');
  signSvg.setAttribute('onmouseup', 'setNotDragging()');

  for(let row = 0; row < 7; row++){
    for(let col = 0; col < 145; col++){
      const led = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
      led.id = `row_${row}_col_${col}`;
      led.setAttribute('class', 'oneled oneled-off');
      led.setAttribute('r', led_r);
      led.setAttribute('cx', led_d*(col+1));
      led.setAttribute('cy', ((row+1)*(led_d))+1);
      led.setAttribute('stroke', "black");
      led.setAttribute('fill', "#333333");
      led.setAttribute('onclick', `ledClicked(${col}, ${row})`);
      led.setAttribute('onmouseenter', `ledEnter(${col}, ${row})`);
      led.setAttribute('onmouseleave', `ledLeave(${col}, ${row})`);
      led.setAttribute('onmousedown', `ledMouseDown(${col}, ${row})`);
      led.setAttribute('onmouseup', `ledMouseUp(${col}, ${row})`);
      signSvg.appendChild(led);
    }
  }
  sign.appendChild(signSvg);
}

function showSignOnline(){
  const status = document.getElementById('signstatus');
  status.classList.remove('offline');
  status.classList.add('online');
  status.classList.remove('bi-x-octagon-fill');
  status.classList.add('bi-check-circle-fill')
  document.getElementById('statustext').innerHTML = '&nbsp;online';
}

function showSignOffline(){
  const status = document.getElementById('signstatus');
  status.classList.remove('online');
  status.classList.add('offline');
  status.classList.remove('bi-check-circle-fill')
  status.classList.add('bi-x-octagon-fill');
  document.getElementById('statustext').innerHTML = '&nbsp;offline';
}

function ledOn(col, row){
  const circle = getLedCircle(col, row);
  circle.setAttribute('fill', LED_ON_COLOR);
  return true;
}

function ledOff(col, row){
  const circle = getLedCircle(col, row);
  circle.setAttribute('fill', LED_OFF_COLOR);
  return false;
}

function toggleLed(col, row){
  if(ledIsOn(col, row)){
    return ledOff(col, row);
  }
  return ledOn(col, row);
}

function ledIsOn(col, row){
  const circle = getLedCircle(col, row);
  return circle.getAttribute('fill') === LED_ON_COLOR;
}

function getLedCircle(col, row){
  return document.getElementById(`row_${row}_col_${col}`);
}

function forEveryLed(cb){
  for(let row = 0; row < 7; row++){
    for(let col = 0; col < 145; col++){
      const led = getLedCircle(col, row);
      cb(led);
    }
  }
}
