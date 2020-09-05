# wtime
Wait for PC-98 batch file

NEC PC-98シリーズで
DosのバッチファイルにWaitを入れたくて作りました。

WTIME time[s]で指定秒(時間は目安)待ちます。

"q"または"Q"で途中終了します。
キーボードからの入力にint 21hを使用しています。

カーソルの消去、表示にPC-98のint 18hのBiosコールを使用しています。
