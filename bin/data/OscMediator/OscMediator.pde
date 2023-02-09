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

  if ("/sounds/add".equals(recievedMessage.addrPattern())) {
    OscMessage message = new OscMessage(recievedMessage.addrPattern());
    message.add(recievedMessage.get(0).intValue());
    message.add(recievedMessage.get(1).floatValue());
    message.add(recievedMessage.get(2).floatValue());
    oscP5.send(message, audioAddress);
  }
}
