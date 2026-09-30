# 02 — NRF24L01 Bring-Up

- **Date:** 21 August 2026
- **Status:** **VERIFIED AFTER DEBUGGING at module/communication-development level**
- **Objective:** Establish a radio-only link-development setup.
- **Hardware:** Arduino Nano transmitter, Arduino Uno receiver in the early bench stage, standard NRF24L01 modules.

## Pin mapping

| NRF24L01 | Nano / Uno |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| CE | D9 |
| CSN | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| IRQ | Not connected |

## Communication/settings

A 10–47 µF local supply capacitor was used/recommended. Stabilization work included an SPI clock around 4 MHz.

## Observed result

Bring-up progressed after debugging repeated `NRF not found` / unstable behavior.

## Known problems

Checks included wiring, CE/CSN, 3.3 V supply, decoupling, reduced SPI clock, and individual modules. At least one suspicious module became abnormally hot.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included sources are **RECONSTRUCTED REFERENCE FIRMWARE**:

- [`nano_tx_reconstructed.ino`](nano_tx_reconstructed.ino)
- [`uno_rx_reconstructed.ino`](uno_rx_reconstructed.ino)

They implement a simple `NRF24 TEST` fixed-message exchange and are not the historical sketches.

## Build requirements and expected output

- Boards: Arduino Nano transmitter and Arduino Uno receiver
- Libraries: built-in `SPI`; external `RF24` library by TMRh20
- Install RF24 from Arduino IDE Library Manager by searching for `RF24` or with `arduino-cli lib install RF24`
- Transmitter serial: `Nano transmitter ready`, then `Sent: NRF24 TEST` or `Send failed`
- Receiver serial: `Uno receiver ready`, then `Received: NRF24 TEST`
- Historical hardware status: bring-up verified after debugging at module/communication-development level; the included code itself is reconstructed

The transmitter and receiver files target different boards. Compile/upload each file individually; do not combine both into one Arduino build.
