# Mitochondria
Mitochondria(レスコン2号機)をPS4コントローラーで動かそう！  
基本的にこっち(devブランチ)で開発していく。

## PS4コントローラー用ライブラリ  
https://www.notion.so/1-278b1970b55980219e2ada5c3cee0d8a?source=copy_link#339b1970b559803386fdc83a87f020f7  
- ライブラリマネージャーで検索してinstall  
- setup内でPS4beginにMACアドレスを渡して、loop内で各ボタンの入力を関数から受け取る(単なるゲッターなのか通信してるのかはよくわからん)。
