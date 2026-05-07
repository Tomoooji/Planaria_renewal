# Planaria

Planaria(レスコン2号機)をPS4コントローラーで動かそう！
基本的にこっち(devブランチ)で開発していく。

## やってみた
### ファイル構成
```text
Planaria_renewal/
├─ src/
│  └─ mitochondria_renewal/
│     ├─ mitochondria_renewal.ino   # 本体
│     ├─ Controller_PS4.h           # 入力受付
│     ├─ MecanumDriver.h            # 出力割り当て
│     ├─ Accelarator.h              # 加速度処理
│     └─ AnalogMotorDriver.h        # モタドラ用ライブラリ
├─ LICENSE
└─ README.md
```
### 処理のイメージ
どうも[ブラウザ上](https://github.com/Tomoooji/Planaria_renewal/tree/example/tomoooji/README.md)じゃないと図にならないみたい
```mermaid
graph TD;
PS4Controller --> MecanumDriver; 
MecanumDriver -.-> MotorDriver;
MecanumDriver --> Accelarator;
Accelarator --> MotorDriver;
```
### 各クラスの詳細
どうも[ブラウザ上](https://github.com/Tomoooji/Planaria_renewal/tree/example/tomoooji/README.md)じゃないと図にならないみたい
```mermaid
classDiagram
    direction TD
    Controller_PS4 *-- InputData
    MecanumDriver *-- ConfigData_leg
    Controller_PS4 *-- ConfigData_ps4
    Controller_PS4 ..> MecanumDriver
    MecanumDriver *-- AnalogMotorDriver
    MecanumDriver *-- Accelarator

    class Controller_PS4{
        -char[] mac_address
        -InputData input;
        -ConfigData_ps4 config;
        +bool begin();
        +bool update();
        +InputData get_input();
        +ConfigData_ps4 get_config();
        -float/int _filter();
    }
    class InputData{
        <<struct>>
        +float angle;
        +int dist;
        +int turn;
    }
    class ConfigData_ps4{
        <<struct>>
        +int ignore_range_stick;
        +int ignore_limit_triger;
    }
    class MecanumDriver{
        -ConfigData_leg config;
        -AnalogMotorDriver[4] motors;
        -Accelarator~int~ acceler;
        +void begin();
        +void update();
        +void move();
    }
    class ConfigData_leg{
        <<struct>>
        +bool reversed[4];
        +int max_speed[4];
    }
    class AnalogMotorDriver{
        -const uint8_t[] _pins;
        -int _max;
        -int _speed;
        +void attach();
        +void apply();
        +void set_speed();
        +int get_speed();
    }
    class Accelarator~T~{
        -T _accel;
        -T _decel;
        +T apply();
    }

```
## 参考資料

### PS4コントローラー用ライブラリ

https://www.notion.so/1-278b1970b55980219e2ada5c3cee0d8a?source=copy_link#339b1970b559803386fdc83a87f020f7

- ライブラリマネージャーで検索してinstall
- setup内でPS4beginにMACアドレスを渡して、loop内で各ボタンの入力を関数から受け取る(単なるゲッターなのか通信してるのかはよくわからん)。

### 過去コード?

https://www.notion.so/ESP32-_-2023-bd5f8e22e0a543179b6db6474eb22fe5?source=copy_link
ぶっちゃけあんまり参考にはならないです。悪しからず
