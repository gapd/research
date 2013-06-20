<?xml version="1.0"?>

<st-source>
<time-stamp>From VisualWorks® Personal Use Edition, 7.8 of 2011年3月30日 on 2012年3月18日 at 17:33:50</time-stamp>


<component-created>
<name>KSU-High</name> <type>package</type>
</component-created><!-- Package KSU-High* -->


<component-property>
<name>KSU-High</name> <type>package</type>
<property>comment</property> <value>'Copyright 2008-2012 KSU (Kyoto Sangyo University). All Right Reserved.
'</value>
</component-property>

<class>
<name>High</name>
<environment>KSU</environment>
<super>Core.Object</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars></inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>KSU-High</category>
<attributes>
<package>KSU-High</package>
</attributes>
</class>

<comment>
<class-id>KSU.High</class-id>
<body>Copyright 2008-2012 KSU (Kyoto Sangyo University). All Right Reserved.</body>
</comment>

<class>
<name>Proxy</name>
<environment>KSU</environment>
<super>Core.UndefinedObject</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars>receiver selectors </inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>KSU-High</category>
<attributes>
<package>KSU-High</package>
</attributes>
</class>

<comment>
<class-id>KSU.Proxy</class-id>
<body>Copyright 2008-2012 KSU (Kyoto Sangyo University). All Right Reserved.</body>
</comment>

<methods>
<class-id>KSU.High class</class-id> <category>page6（代理人）</category>

<body package="KSU-High" selector="page61">page61	"KSU.High page61."	"エラーになるプログラム"	| high |	high := KSU.High new.	^high zzz</body>

<body package="KSU-High" selector="page62">page62	"KSU.High page62."	"代理人を用いるプログラム"	| aValue |	aValue := KSU.Proxy on: 100.	^aValue + 10</body>

<body package="KSU-High" selector="page63">page63	"KSU.High page63."	"代理人にメッセージ変換をたのんでおくプログラム"	| aValue |	aValue := KSU.Proxy on: 100.	aValue transform: #+ to: #-.	^aValue + 10</body>

<body package="KSU-High" selector="page65">page65	"KSU.High page65."	"代理人にメッセージ変換をたのんでおくプログラム"	| aValue |	aValue := KSU.Proxy on: 100.	aValue transform: #たす: to: #+.	aValue transform: #ひく: to: #-.	^(aValue たす: 10) ひく: 20</body>

<body package="KSU-High" selector="page66">page66	"KSU.High page66."	"代理人を入れ子にしてメッセージ変換をたのんでおくプログラム"	| aValue |	aValue := KSU.Proxy on: 100.	aValue transform: #たす: to: #+.	aValue := KSU.Proxy on: aValue.	aValue transform: #ひく: to: #-.	^(aValue たす: 10) ひく: 20</body>

<body package="KSU-High" selector="page64">page64	"KSU.High page64."	"代理人にメッセージ変換をたのんでおくプログラム"	| aValue |	aValue := KSU.Proxy on: 100.	aValue transform: #たす: to: #+.	^aValue たす: 10</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page7（閉包）</category>

<body package="KSU-High" selector="page75">page75	"KSU.High page75."	"Dirty = Copying / Full : (copiedValues notNil) AND (outerContext notNil)"	| x |	x := 2.	[^x squared] value</body>

<body package="KSU-High" selector="page72">page72	"KSU.High page72."	"Clean (and faster) : (copiedValues isEmpty) AND (outerContext isNil)"	| result |	result := [:x | x squared] value: 2.	^result</body>

<body package="KSU-High" selector="page78">page78	"KSU.High page78."	"Copying : (copiedValues notNil) AND (outerContext isNil)"	| continuation x closure |	Transcript clear.	continuation :=			[:v |			Transcript				nextPutAll: v printString;				cr;				flush].	closure :=			[x := 2.			x := x squared]				inspect;				yourself.	3 timesRepeat: [continuation value: closure value]</body>

<body package="KSU-High" selector="page73">page73	"KSU.High page73."	"Full : (copiedValues isNil) AND (outerContext notNil)"	[:x | ^x squared] value: 2</body>

<body package="KSU-High" selector="page76">page76	"KSU.High page76."	"Copying : (copiedValues notNil) AND (outerContext isNil)"	| continuation x closure |	Transcript clear.	continuation :=			[:v |			Transcript				nextPutAll: v printString;				cr;				flush].	x := 2.	closure := [x := x squared]				inspect;				yourself.	3 timesRepeat: [continuation value: closure value]</body>

<body package="KSU-High" selector="page71">page71	"KSU.High page71."	"Dirty (not clean) : (copiedValues notNil) OR (outerContext notNil)"	| result |	[:x | result := x squared] value: 2.	^result</body>

<body package="KSU-High" selector="page77">page77	"KSU.High page77."	"Copying : (copiedValues notNil) AND (outerContext isNil)"	| continuation x closure |	Transcript clear.	continuation :=			[:v |			Transcript				nextPutAll: v printString;				cr;				flush].	x := 2.	closure := [x := x squared]				inspect;				yourself.	3 timesRepeat: [continuation value: closure once]</body>

<body package="KSU-High" selector="page74">page74	"KSU.High page74."	"Copying : (copiedValues notNil) AND (outerContext isNil)"	| x |	x := 2.	^[x squared] value</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page9（アクションボタン）</category>

<body package="KSU-High" selector="page92">page92	"KSU.High page92."	"継続としての閉包"	| aWindow aButton aView |	aWindow := ScheduledWindow new.	aWindow label: 'ActionButton'.	aButton := ValueHolder with: false.	aButton compute: [aWindow controller close].	aView := ActionButtonView model: aButton.	aView label: 'Exit' asText allBold asComposedText.	aWindow component: aView.	aWindow openIn: (100 @ 100 extent: 200 @ 100)</body>

<body package="KSU-High" selector="page91">page91	"KSU.High page91."	"値を有するモノ"	| aButton |	Transcript clear.	aButton := ValueHolder with: false.	aButton compute: 			[Transcript				nextPutAll: aButton value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush].	2 seconds wait.	aButton value: true.	2 seconds wait.	aButton value: false</body>

<body package="KSU-High" selector="page93">page93	"KSU.High page93."	"継続としての閉包"	| aWindow aButton |	aWindow := ScheduledWindow new.	aWindow label: 'ActionButton'.	aButton := JunButtonModel value: false visual: 'Exit' asText allBold.	aButton action: [aWindow controller close].	aWindow component: aButton createButtonView.	aWindow openIn: (100 @ 100 extent: 200 @ 100)</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page8（処理時間・清掃回数）</category>

<body package="KSU-High" selector="page8C">page8C	"KSU.High page8C."	| aClosure |	aClosure :=			[| result |			result := 1.0d.			[result &lt;= 500000000.0d] whileTrue: [result := result + 1.0d].			result yourself].	^aClosure</body>

<body package="KSU-High" selector="page8D">page8D	"KSU.High page8D."	| aClosure aValue |	aClosure :=			[| result |			result := 1.			[result &lt;= 500000000] whileTrue: [result := result + 1].			result yourself].	aValue := ObjectMemory current numScavenges.	^(Time microsecondsToRun: [aClosure value]) -&gt; (ObjectMemory current numScavenges - aValue)</body>

<body package="KSU-High" selector="page87">page87	"KSU.High page87."	"subclass : anObjectが非ポインタ非インデックス型(イミディエイト型)"	| anObject aClass |	anObject := 123.	aClass := anObject class.	^aClass isBits and: [aClass isFixed]	"==&gt; true"</body>

<body package="KSU-High" selector="page86">page86	"KSU.High page86."	"OTE(Object Table Entry)のバイト数を求めます。"	^ObjectMemory current bytesPerOTE	"==&gt; 12"</body>

<body package="KSU-High" selector="page88">page88	"KSU.High page88."	"subclass : anObjectがポインタ非インデックス型"	| anObject aClass |	anObject := Point x: 100 y: 200.	aClass := anObject class.	^aClass isPointers and: [aClass isFixed]	"==&gt; true"</body>

<body package="KSU-High" selector="page89">page89	"KSU.High page89."	"variableSubclass : anObjectがポインタインデックス型"	| anObject aClass |	anObject := OrderedCollection new.	aClass := anObject class.	^aClass isPointers and: [aClass isVariable]	"==&gt; true"</body>

<body package="KSU-High" selector="page84">page84	"KSU.High page84."	"OPのバイト数を求めます。"	^ObjectMemory current bytesPerOOP	"==&gt; 4"</body>

<body package="KSU-High" selector="page8B">page8B	"KSU.High page8B."	| aClosure |	aClosure :=			[| result |			result := 1.			[result &lt;= 500000000] whileTrue: [result := result + 1].			result yourself].	^aClosure</body>

<body package="KSU-High" selector="page80">page80	"KSU.High page80."	| aClosure |	aClosure :=			[| result |			result := 1.			[result &lt;= 500000000] whileTrue: [result := result + 1].			result yourself].	^aClosure value</body>

<body package="KSU-High" selector="page8A">page8A	"KSU.High page8A."	"variableByteSubclass : anObjectが非ポインタインデックス型"	| anObject aClass |	anObject := 123.0d.	aClass := anObject class.	^aClass isBits and: [aClass isVariable]	"==&gt; true"</body>

<body package="KSU-High" selector="page83">page83	"KSU.High page83."	| aClosure |	aClosure :=			[| result |			result := 1.0d.			[result &lt;= 500000000.0d] whileTrue: [result := result + 1.0d].			result yourself].	^Time microsecondsToRun: [aClosure value]</body>

<body package="KSU-High" selector="page81">page81	"KSU.High page81."	| aClosure |	aClosure :=			[| result |			result := 1.0d.			[result &lt;= 500000000.0d] whileTrue: [result := result + 1.0d].			result yourself].	^aClosure value</body>

<body package="KSU-High" selector="page85">page85	"KSU.High page85."	"小さな整数(SmallInteger)の範囲を求めます。"	| value |	value := -1.	[(value subtractOrFail: 1) notNil] whileTrue: [value := value + value].	^value to: (value + 1) negated	"==&gt; (-536870912 to: 536870911)"</body>

<body package="KSU-High" selector="page8E">page8E	"KSU.High page8E."	| aClosure aValue |	aClosure :=			[| result |			result := 1.0d.			[result &lt;= 500000000.0d] whileTrue: [result := result + 1.0d].			result yourself].	aValue := ObjectMemory current numScavenges.	^(Time microsecondsToRun: [aClosure value]) -&gt; (ObjectMemory current numScavenges - aValue)</body>

<body package="KSU-High" selector="page82">page82	"KSU.High page82."	| aClosure |	aClosure :=			[| result |			result := 1.			[result &lt;= 500000000] whileTrue: [result := result + 1].			result yourself].	^Time microsecondsToRun: [aClosure value]</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page4（継続：再帰で階乗を計算）</category>

<body package="KSU-High" selector="page41">page41	"KSU.High page41."	"再帰で階乗を計算するクロージャを用いるプログラム"	| aClosure aValue |	aClosure :=			[:n |			| a |			(n isInteger not or: [n negative]) ifTrue: [^self error: 'boo!'].			a := n isZero ifTrue: [1] ifFalse: [(aClosure value: n - 1) * n].	"再帰している。"			a yourself].	aValue := aClosure value: 10.	Transcript		nextPutAll: aValue printString;		nextPutAll: ' at ';		nextPutAll: Time now printString;		cr;		flush.	^aValue yourself</body>

<body package="KSU-High" selector="page42">page42	"KSU.High page42."	"再帰で階乗を計算する閉包と継続譲渡を用いるプログラムのようだが…"	| aContinuation aClosure |	aContinuation :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush.			^value yourself].	aClosure :=			[:n :continuation |			| a |			(n isInteger not or: [n negative]) ifTrue: [^self error: 'boo!'].			a := n isZero ifTrue: [1] ifFalse: [(aClosure value: n - 1) * n].	"再帰しているが…、引数の数が合わない。"			continuation value: a].	"こんなんで動くわけないじゃないか！！！継続譲渡がわかっておらん！！！"	aClosure value: 10 value: aContinuation.	"階乗を計算する閉包を継続譲渡で実行する。"	self halt	"ここが実行されることはない！"</body>

<body package="KSU-High" selector="page44">page44	"KSU.High page44."	"再帰で階乗を計算する閉包と継続譲渡を用いるプログラムの実行過程をプログラムで可視化するプログラム。"	| anInteger anInterval aStream aCode aTree aResult |	anInteger := 10.	anInterval := 0 to: anInteger.	aStream := String new writeStream.	aCode := 			[aStream				nextPutAll: '"factorial by CPS (Continuation Passing Style)"';				cr.			anInterval do: 					[:n |					| s |					s := n printString.					aStream nextPutAll: '| con' , s , ' | con' , s , ' := '.					n &lt; anInterval last						ifTrue: [aStream nextPutAll: '[:a' , s , ' | ']						ifFalse: 							[aStream								nextPutAll: '[:value | 												Transcript													nextPutAll: value printString;													nextPutAll: '' at '';													nextPutAll: Time now printString;													cr;													flush.													^value yourself].']].			anInterval reverse do: 					[:n |					| s |					s := n printString.					aStream nextPutAll: 'con' , s , ' value: '.					n &gt; anInterval first						ifTrue: 							[| r |							r := (n - 1) printString.							aStream nextPutAll: 'a' , r , ' * ' , s , ']. ']						ifFalse: [aStream nextPutAll: '1']].			aStream contents]					ensure: [aStream close].	aTree := Refactory.Browser.RBParser parseExpression: aCode.	aCode := aTree formattedCode.	aResult := Compiler evaluate: aCode.	Transcript		clear;		nextPutAll: aCode;		cr;		flush.	^aResult	"このようにコンティニュエーション・パッシングをメタなステージで書き下ろせるプログラマ（技術者）はスーパープログラマだろう"</body>

<body package="KSU-High" selector="page43">page43	"KSU.High page43."	"再帰で階乗を計算する閉包と継続譲渡を用いるプログラム"	| aContinuation aClosure |	aContinuation :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush.			^value yourself].	aClosure :=			[:n :continuation |			(n isInteger not or: [n negative]) ifTrue: [^self error: 'boo!'].			n isZero				ifTrue: [continuation value: 1]				ifFalse: [aClosure value: n - 1 value: [:a | continuation value: a * n]].	"再帰で継続譲渡している。"			self halt	"ここが実行されることはない！"].	aClosure value: 10 value: aContinuation.	"階乗を計算する閉包を継続譲渡で実行する。"	self halt	"ここが実行されることはない！"	"コンティニュエーション・パッシング：継続譲渡：後でやることを譲り渡してゆくプログラミング・スタイル"	"コンティニュエーション・パッシングはグラフィカル・ユーザ・インターフェースやWebアプリケーションのイベント処理などに適合して未来の選択を委ねる制御機構"	"グラフィカル・ユーザ・インターフェースにおいて、処理の途中でユーザに非同期で入力を促し、その結果を受けて処理を続けたいことが多発する"	"多くのプログラムでは、ユーザの入力を受け付けるための前処理(リスナー設定)をして、イベントループに入り、コールバック(特定のメソッドを起動)してもらって後処理をする"	"Webアプリケーションにおいても、一端、ユーザーからの入力をフォームなどに書き出して、HTTPサーバに制御を戻し、その後で処理を行う"	"これらはまさに適合するのがコンティニュエーション・パッシングであり、多くのプログラマがすでに用いているのに、そのことに気づいていない"	"前処理と後処理が複雑な文脈を共有しなければならないとき、閉包を作り、イベントループやHTTPサーバに継続をお願いするほうがマッチベター"</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page2（継続：値を有するモノ）</category>

<body package="KSU-High" selector="page23">page23	"KSU.High page23."	"値を保持するオブジェクトを用いるプログラム(3)"	| aValue aContinuation aClosure aValueHolder |	aValue := 15 factorial.	aContinuation :=			[			[:string |			Transcript				nextPutAll: string;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush]					yourself].	aClosure := [:value :continuation | continuation value: value printString].	aValueHolder := ValueHolder new.	aValueHolder with: aContinuation compute: aClosure.	"あなたの値が変化したとき、この継続と一緒にこの閉包を実行してね。"	aValueHolder value: aValue</body>

<body package="KSU-High" selector="page21">page21	"KSU.High page21."	"値を保持するオブジェクトを用いるプログラム(1)"	| aValue aValueHolder |	aValue := 15 factorial.	aValueHolder := ValueHolder new.	"値を保持するオブジェクトを作る。"	aValueHolder value: aValue.	"値を設定する。"	aValue := aValueHolder value.	"値を取り出す。"	Transcript		nextPutAll: aValue printString;		nextPutAll: ' at ';		nextPutAll: Time now printString;		cr;		flush</body>

<body package="KSU-High" selector="page22">page22	"KSU.High page22."	"値を保持するオブジェクトを用いるプログラム(2)"	| aValue aClosure aValueHolder |	aValue := 15 factorial.	aClosure :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush].	aValueHolder := ValueHolder new.	aValueHolder compute: aClosure.	"あなたの値が変化したとき、この閉包を実行してね。"	aValueHolder value: aValue</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page1（継続：閉包を継続として）</category>

<body package="KSU-High" selector="page13">page13	"KSU.High page13."	"時刻をトランスクリプトに書き出すプログラム(3)"	| aClosure aTime |	aClosure :=			[Transcript				nextPutAll: aTime printString;				cr;				flush].	"外部スコープ変数を用いる閉包を生成する。"	aTime := Time now.	aClosure value	"閉包を実行する。"</body>

<body package="KSU-High" selector="page14">page14	"KSU.High page14."	"時刻をトランスクリプトに書き出すプログラム(4)"	| aClosure aTime |	aClosure :=			[:time |			Transcript				nextPutAll: time printString;				cr;				flush].	"外部スコープ変数を用いない閉包を生成する。"	aTime := Time now.	aClosure value: aTime	"値を渡して閉包を実行する。"</body>

<body package="KSU-High" selector="page15">page15	"KSU.High page15."	"時刻をトランスクリプトに書き出すプログラム(5)"	| aClosure aContinuation aTime |	aClosure := [:time :continuation | continuation value: time printString].	aContinuation :=			[:string |			Transcript				nextPutAll: string;				cr;				flush].	aTime := Time now.	aClosure value: aTime value: aContinuation	"値と継続を渡して閉包を実行する。"</body>

<body package="KSU-High" selector="page11">page11	"KSU.High page11."	"時刻をトランスクリプトに書き出すプログラム(1)"	Transcript		nextPutAll: Time now printString;		cr;		flush</body>

<body package="KSU-High" selector="page12">page12	"KSU.High page12."	"時刻をトランスクリプトに書き出すプログラム(2)"	| aTime |	aTime := Time now.	Transcript		nextPutAll: aTime printString;		cr;		flush</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page5（コンテクスト）</category>

<body package="KSU-High" selector="page52">page52	"KSU.High page52."	"デバッガを出してみよう、「Debug it」のメニュー項目を選択するのではなくて"	| aCode aModel aView aController aMethod aResult |	aCode := '^(3 + 4) * 5 factorial'.	aModel := aCode asValue.	aView := TextEditorView model: aModel.	aController := (aView controller)				selectFrom: 1 to: aCode size;				yourself.	aMethod := [aController compileSelection] on: aController class compilationErrorSignal				do: [:anException | anException return: nil].	aMethod ifNil: [^nil].	aResult := aController debug: aMethod.	^aResult</body>

<body package="KSU-High" selector="page51">page51	"KSU.High page51."	"この文脈を得るシュード変数（擬似変数：模擬変数）"	thisContext inspect</body>

<body package="KSU-High" selector="page54">page54	"KSU.High page54."	"実行環境（文脈：コンテクスト）をさかのぼって、どのように起動されたのかを閉包と継続譲渡で調べるプログラム"	| aContinuation aClosure |	aContinuation :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush.			^value yourself].	aClosure :=			[:class :message :continuation |			| aContext aBoolean aBlock |			aContext := thisContext.			aBoolean := true.			aBlock :=					[[aContext notNil and: [aBoolean yourself]] whileTrue: 							[((aContext receiver isKindOf: class) and: [message = aContext selector]) ifTrue: [continuation value: true].							aContext := aContext sender]].			aBlock value.			continuation value: false.			self halt	"ここが実行されることはない！"].	aClosure value: TextEditorController value: #inspectIt value: aContinuation.	self halt	"ここも実行されることはない！"</body>

<body package="KSU-High" selector="page53">page53	"KSU.High page53."	"実行環境（文脈：コンテクスト）をさかのぼって、どのように起動されたのかを閉包と継続譲渡で調べるプログラム"	| aContinuation aClosure |	aContinuation :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush.			^value yourself].	aClosure :=			[:class :message :continuation |			| aContext aBlock |			aContext := thisContext.			aBlock :=					[:context |					((context receiver isKindOf: class) and: [message = context selector]) ifTrue: [continuation value: true].					context sender ifNotNil: [:it | aBlock value: it]].			aBlock value: aContext sender.			continuation value: false.			self halt	"ここが実行されることはない！"].	aClosure value: TextEditorController value: #inspectIt value: aContinuation.	self halt	"ここも実行されることはない！"</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page3（継続：反復で階乗を計算）</category>

<body package="KSU-High" selector="page32">page32	"KSU.High page32."	"反復で階乗を計算するクロージャを用いるプログラム"	| aClosure aValue |	aClosure :=			[:n |			| a |			(n isInteger not or: [n negative]) ifTrue: [^self error: 'boo!'].			a := 1.			(1 to: n) do: [:i | a := a * i].	"反復している。"			a yourself].	aValue := aClosure value: 10.	"階乗を計算する。"	Transcript		nextPutAll: aValue printString;		nextPutAll: ' at ';		nextPutAll: Time now printString;		cr;		flush.	"値を時刻と共にトランスクリプトに書き出す。"	^aValue yourself	"値を応答する。"</body>

<body package="KSU-High" selector="page33">page33	"KSU.High page33."	"反復で階乗を計算する閉包と継続譲渡を用いるプログラム"	| aContinuation aClosure |	aContinuation :=			[:value |			Transcript				nextPutAll: value printString;				nextPutAll: ' at ';				nextPutAll: Time now printString;				cr;				flush.	"値を時刻と共にトランスクリプトに書き出す。"			^value yourself	"値を応答する。"].	aClosure :=			[:n :continuation |			| a |			(n isInteger not or: [n negative]) ifTrue: [^self error: 'boo!'].			a := 1.			(1 to: n) do: [:i | a := a * i].	"反復している。"			continuation value: a].	aClosure value: 10 value: aContinuation.	"階乗を計算する閉包を継続譲渡で実行する。"	self halt	"ここは実行されることはない！"</body>

<body package="KSU-High" selector="page31">page31	"KSU.High page31."	"整数オブジェクトに階乗を計算するためのメッセージを送るプログラム"	| aValue |	aValue := 10 factorial.	"10の階乗を計算する。"	Transcript		nextPutAll: aValue printString;		nextPutAll: ' at ';		nextPutAll: Time now printString;		cr;		flush.	"値を時刻と共にトランスクリプトに書き出す。"	^aValue yourself	"値を応答する。"</body>
</methods>

<methods>
<class-id>KSU.High class</class-id> <category>page0（逐次・並行・約束）</category>

<body package="KSU-High" selector="page03">page03	"KSU.High page03."	"約束：並行と同じ"	| aClosure |	Transcript clear.	aClosure :=			[:aString :howMany |			howMany timesRepeat: 					[Transcript						nextPutAll: aString;						nextPutAll: ': ';						nextPutAll: Time now printString;						cr;						flush.					1000 milliseconds wait]].	[aClosure value: 'Black' value: 2] value.	[aClosure value: 'Red' value: 3] promise.	[aClosure value: 'Green' value: 3] promise.	[aClosure value: 'Blue' value: 3] promise.	[aClosure value: 'White' value: 2] value</body>

<body package="KSU-High" selector="page01">page01	"KSU.High page01."	"逐次"	| aClosure |	Transcript clear.	aClosure :=			[:aString :howMany |			howMany timesRepeat: 					[Transcript						nextPutAll: aString;						nextPutAll: ': ';						nextPutAll: Time now printString;						cr;						flush.					1000 milliseconds wait]].	[aClosure value: 'Black' value: 2] value.	[aClosure value: 'Red' value: 3] value.	[aClosure value: 'Green' value: 3] value.	[aClosure value: 'Blue' value: 3] value.	[aClosure value: 'White' value: 2] value</body>

<body package="KSU-High" selector="page0A">page0A	"KSU.High page0A."	"ブロック化したpage00のプログラムであるpage07のブロッククロージャ数を求める。"	| aClass aSelector aNumber aTree aClosure |	aClass := KSU.High class.	aSelector := #page07.	aNumber := 0.	aTree := JunParseTree class: aClass selector: aSelector.	aClosure :=			[| aBlock |			aBlock := [aNumber := aNumber + 1].			JunControlUtility				assert: 					[Smalltalk.KSU						defineClass: #TransientParseTree						superclass: aTree class fullName asQualifiedReference						indexedType: #none						private: false						instanceVariableNames: ''						classInstanceVariableNames: ''						imports: ''						category: 'KSU-Examples']				do: 					[:transientClass |					| aGraph |					transientClass compile: 'programGraph ^programGraph' classified: #accessing.					aGraph := (transientClass class: aClass selector: aSelector) programGraph.					aGraph nodesDo: [:aNode | ('(block)*' match: aNode labelString) ifTrue: [aBlock value]]]				ensure: [:transientClass | transientClass removeFromSystem].			aTree show.			aNumber yourself].	^aClosure value</body>

<body package="KSU-High" selector="page09">page09	"KSU.High page09."	"ブロック化したpage00のプログラムであるpage07のブロッククロージャ数を求める。"	| aClass aSelector aScanner |	aClass := KSU.High class.	aSelector := #page07.	aScanner := JunProgramScanner class: aClass selector: aSelector.	^aScanner blockNodes size</body>

<body package="KSU-High" selector="page08">page08	"KSU.High page08."	"ブロック化したpage00のプログラムであるpage07のブロッククロージャ数を求める。"	| aClass aSelector aNumber aTree aClosure |	aClass := KSU.High class.	aSelector := #page07.	aNumber := 0.	aTree := JunParseTree class: aClass selector: aSelector.	aClosure :=			[| aBlock anIndex aGraph |			aBlock := [aNumber := aNumber + 1].			anIndex := aTree class allInstVarNames findFirst: [:each | each = 'programGraph'].			aGraph := aTree instVarAt: anIndex.			aGraph nodesDo: [:aNode | ('(block)*' match: aNode labelString) ifTrue: [aBlock value]].			aTree show.			aNumber yourself].	^aClosure value</body>

<body package="KSU-High" selector="page00">page00	"KSU.High page00."	"準備"	| aWindow aCollection aRectangle |	aWindow := (aCollection := Transcript dependents) isEmpty				ifTrue: [VisualLauncher open window]				ifFalse: [aCollection first topComponent].	aRectangle := aWindow displayBox.	aRectangle := aRectangle translatedBy: (aRectangle origin - (50 @ 50)) negated.	aRectangle := aRectangle origin extent: aRectangle width @ 400.	aWindow displayBox: aRectangle.	aWindow := JunLauncher launcherWindow ifNil: [JunLauncher install] ifNotNil: [:it | it yourself].	aWindow collapse.	aWindow := (ScheduledControllers scheduledControllers				detect: [:aController | aController view label = 'Welcome to VisualWorks']				ifNone: [nil]) ifNil: [nil] ifNotNil: [:aController | aController view].	aWindow ifNotNil: [aWindow collapse]</body>

<body package="KSU-High" selector="page04">page04	"KSU.High page04."	"約束：親が子を待ち合わせる"	| aClosure redPromise greenPromise bluePromise |	Transcript clear.	aClosure :=			[:aString :howMany |			howMany timesRepeat: 					[Transcript						nextPutAll: aString;						nextPutAll: ': ';						nextPutAll: Time now printString;						cr;						flush.					1000 milliseconds wait]].	[aClosure value: 'Black' value: 2] value.	redPromise := [aClosure value: 'Red' value: 3] promise.	greenPromise := [aClosure value: 'Green' value: 3] promise.	bluePromise := [aClosure value: 'Blue' value: 3] promise.	redPromise value.	greenPromise value.	bluePromise value.	[aClosure value: 'White' value: 2] value</body>

<body package="KSU-High" selector="page02">page02	"KSU.High page02."	"並行"	| aClosure |	Transcript clear.	aClosure :=			[:aString :howMany |			howMany timesRepeat: 					[Transcript						nextPutAll: aString;						nextPutAll: ': ';						nextPutAll: Time now printString;						cr;						flush.					1000 milliseconds wait]].	[aClosure value: 'Black' value: 2] value.	[aClosure value: 'Red' value: 3] fork.	[aClosure value: 'Green' value: 3] fork.	[aClosure value: 'Blue' value: 3] fork.	[aClosure value: 'White' value: 2] value</body>

<body package="KSU-High" selector="page07">page07	"KSU.High page07."	"page00のプログラムをのブロック化して(３つのブロッククロージャにわけて)みよう。"		[| aWindow aCollection aRectangle |	aWindow := (aCollection := Transcript dependents) isEmpty				ifTrue: [VisualLauncher open window]				ifFalse: [aCollection first topComponent].	aRectangle := aWindow displayBox.	aRectangle := aRectangle translatedBy: (aRectangle origin - (50 @ 50)) negated.	aRectangle := aRectangle origin extent: aRectangle width @ 400.	aWindow displayBox: aRectangle]			value.		[| aWindow |	aWindow := JunLauncher launcherWindow ifNil: [JunLauncher install] ifNotNil: [:it | it yourself].	aWindow collapse]			fork.		[| aWindow |	aWindow := (ScheduledControllers scheduledControllers				detect: [:aController | aController view label = 'Welcome to VisualWorks']				ifNone: [nil]) ifNil: [nil] ifNotNil: [:aController | aController view].	aWindow ifNotNil: [aWindow collapse]]			promise</body>

<body package="KSU-High" selector="page06">page06	"KSU.High page06."	"さるクラスのあるメソッドの中に含まれるブロッククロージャの数を応答する。"	| aClass aSelector aNumber aTree aClosure |	aClass := Collection.	aSelector := #select:.	aNumber := 0.	aTree := JunParseTree class: aClass selector: aSelector.	aClosure :=			[| anIndex aGraph |			anIndex := aTree class allInstVarNames findFirst: [:each | each = 'programGraph'].			aGraph := aTree instVarAt: anIndex.			aGraph nodesDo: [:aNode | ('(block)*' match: aNode labelString) ifTrue: [aNumber := aNumber + 1]].			Transcript				cr;				show: aNumber printString.			aTree show.			aNumber yourself].	^aClosure value</body>

<body package="KSU-High" selector="page05">page05	"KSU.High page05."	"約束：親が子を待ち合わせる間に値のやり取り"	| aBlock aClosure redPromise greenPromise bluePromise |	Transcript clear.	aBlock :=			[:aString |			Transcript				nextPutAll: aString;				nextPutAll: ': ';				nextPutAll: Time now printString;				cr;				flush].	aClosure := [:aString :howMany | howMany timesRepeat: 					[aBlock value: aString.					1000 milliseconds wait]].	redPromise := greenPromise := bluePromise := nil.	[aClosure value: 'Black' value: 2] value.	redPromise := 			[redPromise value: '赤'.			aClosure value: 'Red' value: 3] promise.	greenPromise := 			[aClosure value: 'Green' value: 1.			greenPromise value: '緑'.			aClosure value: 'Green' value: 2] promise.	bluePromise := 			[aClosure value: 'Blue' value: 2.			bluePromise value: '青'.			aClosure value: 'Blue' value: 1] promise.	aBlock value: redPromise value.	aBlock value: greenPromise value.	aBlock value: bluePromise value.	[aClosure value: 'White' value: 2] value</body>
</methods>


<methods>
<class-id>KSU.Proxy class</class-id> <category>instance creation</category>

<body package="KSU-High" selector="on:">on: anObject	^(self basicNew)		initialize;		setReceiver: anObject;		yourself</body>
</methods>

<methods>
<class-id>KSU.Proxy class</class-id> <category>examples</category>

<body package="KSU-High" selector="example5">example5	"KSU.Proxy example5."	| proxy |	proxy := KSU.Proxy on: 100 @ 200.	proxy transform: #たす: to: #+.	proxy transform: #ひく: to: #-.	proxy := (proxy たす: 10 @ 20) ひく: 100 @ 200.	Transcript		cr;		show: proxy isNil printString.	proxy		ifNil: 			[Transcript				cr;				show: nil printString]		ifNotNil: 			[:it |			Transcript				cr;				show: it printString].	^proxy</body>

<body package="KSU-High" selector="example3">example3	"KSU.Proxy example3."	| proxy |	proxy := KSU.Proxy on: 100 @ 200.	proxy transform: #たす: to: #+.	proxy transform: #ひく: to: #-.	proxy := (proxy たす: 10 @ 20) ひく: 100 @ 200.	Transcript		cr;		show: proxy printString.	^proxy</body>

<body package="KSU-High" selector="example1">example1	"KSU.Proxy example1."	| proxy |	proxy := KSU.Proxy on: 100 @ 200.	proxy := proxy + (10 @ 20).	Transcript		cr;		show: proxy printString.	^proxy</body>

<body package="KSU-High" selector="example4">example4	"KSU.Proxy example4."	| proxy value |	proxy := KSU.Proxy on: 100 @ 200.	proxy := KSU.Proxy on: proxy.	proxy transform: #たす: to: #+.	proxy transform: #ひく: to: #-.	value := ((proxy たす: 10 @ 20) ひく: 100 @ 200) value.	Transcript		cr;		show: value printString.	^value</body>

<body package="KSU-High" selector="example2">example2	"KSU.Proxy example2."	| proxy |	proxy := KSU.Proxy on: 100 @ 200.	proxy transform: #+ to: #-.	proxy := proxy + (10 @ 20).	Transcript		cr;		show: proxy printString.	^proxy</body>
</methods>


<methods>
<class-id>KSU.Proxy</class-id> <category>controlling</category>

<body package="KSU-High" selector="ifNotNil:">ifNotNil: aBlock	^self doesNotUnderstand: (MessageSend				receiver: self				selector: #ifNotNil:				arguments: (Array with: aBlock))</body>

<body package="KSU-High" selector="ifNil:">ifNil: aBlock	^self doesNotUnderstand: (MessageSend				receiver: self				selector: #ifNil:				arguments: (Array with: aBlock))</body>

<body package="KSU-High" selector="ifNil:ifNotNil:">ifNil: nilBlock ifNotNil: notNilBlock	^self doesNotUnderstand: (MessageSend				receiver: self				selector: #ifNil:ifNotNil:				arguments: (Array with: nilBlock with: notNilBlock))</body>

<body package="KSU-High" selector="ifNotNil:ifNil:">ifNotNil: notNilBlock ifNil: nilBlock	^self doesNotUnderstand: (MessageSend				receiver: self				selector: #ifNotNil:ifNil:				arguments: (Array with: notNilBlock with: nilBlock))</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>testing</category>

<body package="KSU-High" selector="notNil">notNil	^(self doesNotUnderstand: (MessageSend receiver: self selector: #notNil)) value</body>

<body package="KSU-High" selector="isNil">isNil	^(self doesNotUnderstand: (MessageSend receiver: self selector: #isNil)) value</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>accessing</category>

<body package="KSU-High" selector="value">value	| anObject |	anObject := receiver.	[anObject isKindOf: self class] whileTrue: [anObject := anObject value].	^anObject</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>error handling</category>

<body package="KSU-High" selector="doesNotUnderstand:">doesNotUnderstand: aMessage	| selector arguments result clone |	selector := aMessage selector.	arguments := aMessage arguments.	result := (selectors at: selector ifAbsent: [nil])				ifNil: [receiver perform: selector withArguments: arguments]				ifNotNil: [:transformedSelector | receiver perform: transformedSelector withArguments: arguments].	clone := self copy.	clone setReceiver: result.	^clone</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>private</category>

<body package="KSU-High" selector="setReceiver:">setReceiver: anObject	receiver := anObject</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>copying</category>

<body package="KSU-High" selector="shallowCopy">shallowCopy	&lt;primitive: 532&gt;	</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>removing</category>

<body package="KSU-High" selector="retractTransformationAt:">retractTransformationAt: aSelectorSymbol	^selectors removeKey: aSelectorSymbol ifAbsent: [nil]</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>initialize-release</category>

<body package="KSU-High" selector="initialize">initialize	receiver := nil.	selectors := IdentityDictionary new.	^self</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>printing</category>

<body package="KSU-High" selector="storeOn:">storeOn: aStream	aStream nextPutAll: '('.	self class storeOn: aStream.	aStream nextPutAll: ' on: ('.	receiver storeOn: aStream.	aStream nextPutAll: '))'</body>

<body package="KSU-High" selector="printOn:">printOn: aStream	aStream nextPutAll: '('.	self class printOn: aStream.	aStream nextPutAll: ' on: ('.	receiver printOn: aStream.	aStream nextPutAll: '))'</body>
</methods>

<methods>
<class-id>KSU.Proxy</class-id> <category>adding</category>

<body package="KSU-High" selector="transform:to:">transform: aSelectorSymbol to: anotherSelectorSymbol	selectors at: aSelectorSymbol put: anotherSelectorSymbol</body>
</methods>



</st-source>
