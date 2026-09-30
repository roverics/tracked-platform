# 03 — Nano-to-Mega Wireless Link

- **Date:** 31 August–3 September 2026
- **Status:** **VERIFIED**
- **Objective:** Send a fixed value, then live joystick X/Y values, from Nano to Mega.
- **Hardware:** Nano, Mega 2560, two standard NRF24L01 modules; joystick in the later stage.

## Pin mapping

| NRF24L01 | Nano | Mega 2560 |
|---|---:|---:|
| CE | D9 | D9 |
| CSN | D10 | D8 |
| SCK | D13 | D52 |
| MOSI | D11 | D51 |
| MISO | D12 | D50 |
| VCC | 3.3 V | 3.3 V |
| GND | GND | GND |
| SS/master | — | D53 |

## Communication/settings

- Address: `00001`
- Channel: 76
- Data rate: 250 kbps
- Successful joystick-era RF24 SPI operation: approximately 1 MHz

## Observed result

The Mega received `GOT: 123`; real joystick X/Y values were subsequently received.

## Known problems

Range, packet loss, and latency were not characterized.

## Firmware provenance

Exact historical source file not currently archived in this repository.

Included sources are **RECONSTRUCTED REFERENCE FIRMWARE**:

- [`nano_tx_reconstructed.ino`](nano_tx_reconstructed.ino)
- [`mega_rx_reconstructed.ino`](mega_rx_reconstructed.ino)

They recreate the documented fixed-value milestone but are not the historical files.

## Build requirements and expected output

- Boards: Arduino Nano transmitter and Arduino Mega 2560 receiver
- Libraries: built-in `SPI`; external `RF24` library by TMRh20
- Install RF24 from Arduino IDE Library Manager or run `arduino-cli lib install RF24`
- Nano serial: `Sent: 123` or `Send failed`
- Mega serial: `GOT: 123` when the packet is received
- Historical hardware result: `GOT: 123` and later joystick data were verified; compilation of these reconstructed files does not repeat that validation

The transmitter and receiver files target different boards. Compile/upload each file individually; do not combine both into one Arduino build.
