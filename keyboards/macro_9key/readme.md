# Macro 9Key

A 9-key macro keyboard designed for Pro Micro (ATmega32U4).

## Layout

```
Row 0: [K00] [K01] [K02] [K03] [---]
Row 1: [K10] [K11] [K12] [K13] [K14]
```

## Hardware

- **Controller**: Pro Micro (ATmega32U4)
- **Bootloader**: Caterina
- **Matrix**: 2 rows × 5 columns
- **Diodes**: Required (COL2ROW)

## Pin Configuration

- **Rows**: D0, D1
- **Columns**: D2, D3, D4, D5, D6

## Building

```bash
qmk compile -kb macro_9key -km default
```

## Flashing

```bash
qmk flash -kb macro_9key -km default
```

