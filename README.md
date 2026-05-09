# Planaria
Planaria(レスコン2号機)をPS4コントローラーで動かそう！  

## 更新履歴
- 2026-05-08 ファイル構造を整理

## ファイル構成
```text
Planaria_renewal/
├─ mitochondria_renewal/
│  ├─ src/
│  │  └─ Dummy
│  └─ mitochondria_renewal.ino
├─ connecting_test/
│  └─connecting_test.ino
├─ LICENSE
└─ README.md
```

srcフォルダを中に作ることで一緒にコンパイルしてくれる(中でもう一段階ネストすることも可能)

## 実行環境
- ArduinoIDE(ver.)
- ESP32(ver.) (ライセンス)
- ,,,etc.

## 基本仕様

## 参考資料
### PS4コントローラー用ライブラリ  
https://www.notion.so/1-278b1970b55980219e2ada5c3cee0d8a?source=copy_link#339b1970b559803386fdc83a87f020f7  
- ライブラリマネージャーで検索してinstall  
- setup内でPS4beginにMACアドレスを渡して、loop内で各ボタンの入力を関数から受け取る(単なるゲッターなのか通信してるのかはよくわからん)。
### 過去コード?
https://www.notion.so/ESP32-_-2023-bd5f8e22e0a543179b6db6474eb22fe5?source=copy_link
ぶっちゃけあんまり参考にはならないです。悪しからず
