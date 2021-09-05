

let socket = null;
let connected = false;

console.log('client ws starting.');

doConnect();

function doConnect(){

  socket = new WebSocket('ws://localhost:8080/client');

  socket.addEventListener('open', event => {
    console.log('ws connection established');
    connected = true;
  });

  socket.addEventListener('message', onMessage);

  socket.addEventListener('close', event => {
    console.log('ws disconnected');
    socket = null;
    showSignOffline();
    doConnect();
  });

}

function onMessage(event){
  console.log('Message from server ', event.data);
  const message = JSON.parse(event.data);
  if(message.event === "status"){
    doStatusUpdate(message);
  }
}

function doStatusUpdate(message){
  if(message.online){
    showSignOnline();
  }
  else {
    showSignOffline();
  }
  updateDisplay(message.content);
}

function updateDisplay(content){
  const buff = atob(content); //base64 decode
  for(let row=0; row < 7; row++){
    for(let rowbyte=0; rowbyte < 19; rowbyte++){
      const b = buff.charCodeAt((19*row) + rowbyte);
      for(let bp = 0; bp < 8; bp++){
        const col = (8 * rowbyte) + bp;
        const col_adj = col - 6;
        if((col_adj < 0) || (col_adj > 144)) continue;
        const circle = document.getElementById(`row_${row}_col_${col_adj}`);
        if((rowbyte == 0) && (bp < 8)) continue;
        if(b & (1 << bp)){
          circle.setAttribute('fill', '#850c1e');
        }
        else{
          circle.setAttribute('fill', '#2e2e2e');
        }
      }
    }
  }
}
