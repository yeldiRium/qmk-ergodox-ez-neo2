# NEO2 for ErgoDox EZ on QWERTZ

Inspired by [ergodox_osx_neo2](https://github.com/mjonuschat/ergodox_osx_neo2) by [mjonuschat](https://github.com/mjonuschat), built for the [Ergodox EZ](https://ergodox-ez.com/).

## Layers

This is a [Neo 2.0](https://www.neo-layout.org/) layout adjusted for the [ErgoDox EZ](https://ergodox-ez.com/). It is my personal
optimization and I will not take requests. If you like it, feel free to use it,
tweak it, whatever.

I also have an [alternative layout for the Corne Keyboard](https://github.com/yeldiRium/qmk-crkbd-neo2).

[Layer 1](#layer-1) Lowercase, upppercase and typographical characters
[Layer 2](#layer-2) Special characters for programming
[Layer 3](#layer-3) WASD-like movement keys and number block
[Layer 4](#layer-4) Rough de qwertz layout
[Layer 5](#layer-5) Function keys
[Layer 6](#layer-6) Cursor movement

## Legend

 * Keys marked with `----` are dead keys.
 * Blank keys are transparent and fall through to lower levels.
 * Keys marked with `xxxx` are modifiers that are currently pressed while the layer is active.

## Layer 1

This layer implements NEO layers 1 and 2.

```
NEO_1: Basic layer

,------------------------------------------------.           ,------------------------------------------------.
| ---- |  1/° |  2/§ |  3/¹ |  4/» |  5/« | ---- |           |  DE  |  6/$ |  7/€ |  8/„ |  9/“ |  0/” | -/—  |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| TAB  |   X  |   V  |   L  |   C  |   W  | MOVE |           | MOVE |   K  |   H  |   G  |   F  |   Q  |   ß  |
|------+------+------+------+------+------| TAB<-|           | TAB->|------+------+------+------+------+------|
| NEO3 |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y  |
|------+------+------+------+------+------| MB1  |           | MB2  |------+------+------+------+------+------|
| LSFT |   Ü  |   Ö  |   Ä  |   P  |   Z  |      |           |      |   B  |   M  |  ,/– |  ./• |   J  | RSFT |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------`
  | ---- | ---- | ---- | ---- | NEO4 |                                   | NEO4 | NAV  | ---- | ---- | ---- |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | APP  |ctrl+s|       | ---- | FKEY |
                                ,------|------|------|       |------+------+------.
                                |      |      | AC   |       | AC   |      |      |
                                | LGUI | LALT |------|       |------| ALTG |Space |
                                |      |      | LCTRL|       | RCTRL|      |      |
                                `--------------------'       `--------------------'
```

The `AC` key sends left alt and left control.

## Layer 2

This layer implements NEO layer 3.

```
,------------------------------------------------.           ,------------------------------------------------.
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | ---- |----  | ---- | ---- | ---- |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| ---- |   …  |   _  |   [  |   ]  |   ^  | MOVE |           | MOVE |   !  |   <  |   >  |   =  |   &  |   €  |
|------+------+------+------+------+------| TAB<-|           | TAB->|------+------+------+------+------+------|
| xxxx |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   :  |   @  |
|------+------+------+------+------+------|      |           |      |------+------+------+------+------+------|
|      |   #  |   $  |   |  |   ~  |   `  |      |           |      |   +  |   %  |   "  |   '  |   ;  |      |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
  | ---- | ---- | ---- | ---- |      |                                   |      |      | ---- | ---- | ---- |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | ---- | ---- |       | ---- | ---- |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       |      |      |      |
                                |      |      |------|       |------|      |      |
                                |      |      |      |       |      |      |      |
                                `--------------------'       `--------------------'
```

## Layer 3

This layer implements NEO layer 4.

```
,------------------------------------------------.           ,------------------------------------------------.
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | Tab  |   /  |   *  |   -  | ---- |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| ---- | PgUp |   ⌫  |  Up  |   ⌦  | PgDn | ---- |           | ---- |   ¡  |   7  |   8  |   9  |   +  | ---- |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| ---- | Home | Left | Down | Right| End  |------|           |------|   ¿  |   4  |   5  |   6  |   ,  |   .  |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
|      | Esc  | Tab  | Ins  |Return| Undo | ---- |           | ---- |   :  |   1  |   2  |   3  |   ;  | ---- |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
  | ---- | ---- | ---- | ---- | xxxx |                                   | xxxx |   0  | ---- | ---- | ---- |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | ---- | ---- |       | ---- | ---- |
                                ,------|------|------|       |------+------+------.
                                |      |      |      |       |      |      |      |
                                |      |      |------|       |------|      |      |
                                |      |      |      |       |      |      |      |
                                `--------------------'       `--------------------'
```

## Layer 4

A rough qwertz layout ajusted to my gaming likes.

```
,------------------------------------------------.           ,------------------------------------------------.
| ESC  |   1  |   2  |   3  |   4  |   5  | ESC  |           | NEO_1|   6  |   7  |   8  |   9  |   0  |   ß  |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| TAB  |   Q  |   W  |   E  |   R  |   T  | ---- |           | ---- |   Z  |   U  |   I  |   O  |   P  |   Ü  |
|------+------+------+------+------+------|      |           |      |------+------+------+------+------+------|
| LSFT |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä  |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| LSFT |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  | RSFT |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
  | LCTL | LGUI | LALT | ---- | FKEYS|                                   | ---- | ---- | ---- | ---- | RGUI |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | ---- | ---- |       | RALT | RCTRL|
                                ,------|------|------|       |------+------+------.
                                |      |      | ---- |       | ---- |      |      |
                                | SPCE | LALT |------|       |------| ENTR | SPCE |
                                |      |      | LCTL |       | BSPC |      |      |
                                `--------------------'       `--------------------'
```

## Layer 5

This layer implements function and multimedia keys.

```
,------------------------------------------------.           ,------------------------------------------------.
| Mprv |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | Volu |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| Mply | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | ---- | ---- | ---- | ---- | Vold |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| Mnxt | ---- | ---- | ---- | ---- | ---- |------|           |------| ---- | ---- | ---- | ---- | ---- | Mute |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
  | ---- | ---- | ---- | ---- | ---- |                                   | ---- | ---- | ---- | ---- | ---- |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | ---- | ---- |       | ---- | xxxx |
                                ,------|------|------|       |------+------+------.
                                |      |      | ---- |       | ---- |      |      |
                                | ---- | ---- |------|       |------| ---- | ---- |
                                |      |      | ---- |       | ---- |      |      |
                                `--------------------'       `--------------------'
```

## Layer 6

This layer implements mouse navigation

```
,------------------------------------------------.           ,------------------------------------------------.
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|------+------+------+------+------+-------------|           |------+------+------+------+------+------+------|
| ---- | ---- | ---- | Mu   | ---- | ---- | ---- |           | ---- | ---- | LClk | MWu  | RClk | ---- | ---- |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| ---- | ---- | Ml   | Md   | Mr   | ---- |------|           |------| ---- | MWl  | MWd  | MWr  | ---- | ---- |
|------+------+------+------+------+------| ---- |           | ---- |------+------+------+------+------+------|
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |           | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
`------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
  | ---- | ---- | ---- | ---- | ---- |                                   | ---- | xxxx | ---- | ---- | ---- |
  `----------------------------------'                                   `----------------------------------'
                                       ,-------------.       ,-------------.
                                       | ---- | ---- |       | ---- | ---- |
                                ,------|------|------|       |------+------+------.
                                |      |      | ---- |       | ---- |      |      |
                                | LGUI | LALT |------|       |------| RALT | ---- |
                                |      |      | LCTL |       | RCTL |      |      |
                                `--------------------'       `--------------------'
```
