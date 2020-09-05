# wtime
Wait for PC-98 batch file

NEC PC-98シリーズで
DosのバッチファイルにWaitを入れたくて作りました。

LSI C-86 試食版でコンパイルしています。

WTIME time[s]で指定秒(時間は目安)待ちます。

"q"または"Q"で途中終了します。
キーボードからの入力にint 21hを使用しています。

カーソルの消去、表示にPC-98のint 18hのBiosコールを使用しています。

FreeDOS(98) + Neko Project 21/W  
FreeDOS(98) + PC-9801RX21(実機)で試しています。
