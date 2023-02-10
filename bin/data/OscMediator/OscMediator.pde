import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress audioAddress;

void setup() {
  size(400, 400);
  oscP5 = new OscP5(this, 12000);
  audioAddress = new NetAddress("127.0.0.1", 12001);
}


void draw() {
  background(0);
}

void oscEvent(OscMessage recievedMessage) {
  print("### received an osc message.");
  print(" addrpattern: " + recievedMessage.addrPattern());
  println(" typetag: " + recievedMessage.typetag());


  String pattern = recievedMessage.addrPattern();
  
  if ("/sounds/add".equals(pattern)) {
    OscMessage message = new OscMessage(recievedMessage.addrPattern());
    message.add(recievedMessage.get(0).intValue());
    message.add(recievedMessage.get(1).floatValue());
    message.add(recievedMessage.get(2).floatValue());
    oscP5.send(message, audioAddress);
  } else if ("/listener/move".equals(pattern)) {
    OscMessage message = new OscMessage(recievedMessage.addrPattern());
    message.add(recievedMessage.get(0).floatValue());
    message.add(recievedMessage.get(1).floatValue());
    oscP5.send(message, audioAddress);
  } else if ("/sounds/clear".equals(pattern)) {
    OscMessage message = new OscMessage(recievedMessage.addrPattern());
    oscP5.send(message, audioAddress);
  }
}
