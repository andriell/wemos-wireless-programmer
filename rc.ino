RCSwitch2 rc433 = RCSwitch2();
RCSwitch2 rc315 = RCSwitch2();

void ICACHE_RAM_ATTR handleInterrupt433() {
  rc433.handleInterrupt();
}

void ICACHE_RAM_ATTR handleInterrupt315() {
  rc315.handleInterrupt();
}

void rcSetup() {
  rc433.enableReceive(WEMOS_D2);
  rc315.enableReceive(WEMOS_D3);
  attachInterrupt(WEMOS_D2, handleInterrupt433, CHANGE);
  attachInterrupt(WEMOS_D3, handleInterrupt315, CHANGE);
}

void rcLoop() {
  if (rc433.available()) {
    dbg(1, "Received 433 ");
    dbg(1, rc433.getReceivedValue());
    dbg(1, " / ");
    dbg(1, rc433.getReceivedBitlength());
    dbg(1, "bit ");
    dbg(1, "Protocol: ");
    dbgLn(1, rc433.getReceivedProtocol());
    rc433.resetAvailable();
  }

  if (rc315.available()) {
    dbg(1, "Received 315 ");
    dbg(1, rc315.getReceivedValue());
    dbg(1, " / ");
    dbg(1, rc315.getReceivedBitlength());
    dbg(1, "bit ");
    dbg(1, "Protocol: ");
    dbgLn(1, rc315.getReceivedProtocol());
    rc315.resetAvailable();
  }
}
