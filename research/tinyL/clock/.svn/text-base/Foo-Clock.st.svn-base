<?xml version="1.0"?>

<st-source>
<time-stamp>From VisualWorks® NonCommercial, 7.7 of 2009年12月15日 on 2010年10月13日 at 05:19:56</time-stamp>


<component-created>
<name>Foo-Clock</name> <type>package</type>
</component-created><!-- Package Foo-Clock* -->


<component-property>
<name>Foo-Clock</name> <type>package</type>
<property>comment</property> <value>'Programming Language (AOKI Atsushi)
'</value>
</component-property>

<class>
<name>FooClockView</name>
<environment>Smalltalk</environment>
<super>Jun.JunView</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars></inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>Foo-Clock</category>
<attributes>
<package>Foo-Clock</package>
</attributes>
</class>

<comment>
<class-id>FooClockView</class-id>
<body>Programming Language (AOKI Atsushi)</body>
</comment>

<class>
<name>FooDigitalClockView</name>
<environment>Smalltalk</environment>
<super>FooClockView</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars>cachedStyle </inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>Foo-Clock</category>
<attributes>
<package>Foo-Clock</package>
</attributes>
</class>

<comment>
<class-id>FooDigitalClockView</class-id>
<body>Programming Language (AOKI Atsushi)</body>
</comment>

<class>
<name>FooClockModel</name>
<environment>Smalltalk</environment>
<super>Jun.JunModel</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars>clockProcess </inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>Foo-Clock</category>
<attributes>
<package>Foo-Clock</package>
</attributes>
</class>

<comment>
<class-id>FooClockModel</class-id>
<body>Programming Language (AOKI Atsushi)</body>
</comment>

<class>
<name>FooAnalogClockView</name>
<environment>Smalltalk</environment>
<super>FooClockView</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars>cachedImage cachedTime </inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>Foo-Clock</category>
<attributes>
<package>Foo-Clock</package>
</attributes>
</class>

<comment>
<class-id>FooAnalogClockView</class-id>
<body>Programming Language (AOKI Atsushi)</body>
</comment>

<class>
<name>FooClockController</name>
<environment>Smalltalk</environment>
<super>Jun.JunController</super>
<private>false</private>
<indexed-type>none</indexed-type>
<inst-vars></inst-vars>
<class-inst-vars></class-inst-vars>
<imports></imports>
<category>Foo-Clock</category>
<attributes>
<package>Foo-Clock</package>
</attributes>
</class>

<comment>
<class-id>FooClockController</class-id>
<body>Programming Language (AOKI Atsushi)</body>
</comment>

<methods>
<class-id>FooClockView</class-id> <category>display box accessing</category>

<body package="Foo-Clock" selector="bounds:">bounds: ignore	super bounds: ignore.	self flushCache</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="flushCache">flushCache	^self</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext	| center radius time |	self clearInside.	center := self bounds center.	radius := self bounds extent // 2 - 20.	time := self model currentTime.	(Array		with: time hours * 5 + (time minutes / 12)		with: time minutes		with: time seconds) with: #(#(0.6 3) #(0.9 2) #(1.0 1))			do: 				[:value :array |				| x y p |				x := (value * 6 - 90) degreesToRadians cos.				y := (value * 6 - 90) degreesToRadians sin.				p := (x @ y * (radius * array first)) rounded.				graphicsContext					lineWidth: array last;					displayLineFrom: center to: center + p]</body>

<body package="Foo-Clock" selector="displayOn:">displayOn: graphicsContext	self isOpen ifFalse: [^nil].	self displayTimeOn: graphicsContext</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>initialize-release</category>

<body package="Foo-Clock" selector="initialize">initialize	super initialize.	self flushCache</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>visual properties</category>

<body package="Foo-Clock" selector="selectionBackgroundColor">selectionBackgroundColor	^ColorValue white</body>

<body package="Foo-Clock" selector="selectionForegroundColor">selectionForegroundColor	^ColorValue black</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>updating</category>

<body package="Foo-Clock" selector="update:">update: aspectSymbol	self errorSignal handle: [:exception | exception return] do: [self displayOn: self graphicsContext]</body>
</methods>

<methods>
<class-id>FooClockView</class-id> <category>controller accessing</category>

<body package="Foo-Clock" selector="defaultControllerClass">defaultControllerClass	^FooClockController</body>
</methods>


<methods>
<class-id>FooClockController</class-id> <category>control defaults</category>

<body package="Foo-Clock" selector="yellowButtonActivity">yellowButtonActivity	self yellowButtonShiftActivity ifTrue: [^nil].	^(Menu labels: self model currentDateString) startUp</body>

<body package="Foo-Clock" selector="redButtonActivity">redButtonActivity	^self</body>
</methods>


<methods>
<class-id>FooClockModel class</class-id> <category>tips</category>

<body package="Foo-Clock" selector="sampleCodeToBrowseSourceCode">sampleCodeToBrowseSourceCode	"FooClockModel sampleCodeToBrowseSourceCode."	| aClass aSelector aString aNode aText |	aClass := FooAnalogClockView.	aSelector := #displayTickHandOn:.	aString := (aClass sourceCodeAt: aSelector) asString.	aNode := Refactory.Browser.RBParser parseMethod: aString.	aText := aNode formattedCode asText makeSelectorBoldIn: aClass.	TextEditorView		edit: (ValueHolder with: aText)		label: 'Source Code'		icon: nil		extent: 600 @ 400</body>

<body package="Foo-Clock" selector="saveAsFooAndExercise">saveAsFooAndExercise	"FooClockModel saveAsFooAndExercise."	| fooString exerciseString aPackage aFilename aCollection |	fooString := 'Foo-Clock'.	exerciseString := 'Exercise-Clock'.	aCollection := (OrderedCollection new)				add: (Array							with: FooAnalogClockView yourself							with: #displayTickHandOn:							with: 'displaying'							with: #edit);				add: (Array							with: FooDigitalClockView yourself							with: #displayTimeOn:							with: 'displaying'							with: #edit);				add: (Array							with: FooClockModel class							with: #saveAsFooAndExercise							with: 'tips'							with: #delete);				yourself.	aPackage := Store.Registry packageNamed: fooString.	aPackage isNil ifTrue: [aPackage := Store.PackageModel named: fooString].	aFilename := Filename defaultDirectory construct: fooString , '.st'.	aPackage fileOutOnFileNamed: aFilename.	aCollection do: 			[:anArray |			| aClass aSelector aProtocol aSymbol aCode readStream writeStream aCharacter |			aClass := anArray at: 1.			aSelector := anArray at: 2.			aProtocol := anArray at: 3.			aSymbol := anArray at: 4.			anArray at: 4 put: (aCode := aClass sourceCodeAt: aSelector).			aSymbol = #edit				ifTrue: 					[readStream := ReadStream on: aCode.					writeStream := WriteStream on: String new.										[readStream atEnd not and: 							[aCharacter := readStream next.							(aCharacter = Character cr) not]]							whileTrue: [writeStream nextPut: aCharacter].					writeStream						cr;						tab;						nextPut: $";						cr.					[readStream atEnd not] whileTrue: 							[aCharacter := readStream next.							aCharacter isSeparator ifTrue: [writeStream nextPut: aCharacter] ifFalse: [writeStream nextPut: $?]].					writeStream						cr;						tab;						nextPut: $".					aCode := writeStream contents.					readStream close.					writeStream close.					aClass compile: aCode classified: aProtocol asSymbol].			aSymbol = #delete ifTrue: [aClass removeSelector: aSelector]].	aFilename := Filename defaultDirectory construct: exerciseString , '.st'.	aPackage fileOutOnFileNamed: aFilename.	aCollection do: 			[:anArray |			| aClass aProtocol aCode |			aClass := anArray at: 1.			aProtocol := anArray at: 3.			aCode := anArray at: 4.			aClass compile: aCode classified: aProtocol asSymbol].	^aPackage</body>

<body package="Foo-Clock" selector="sampleCodeToBrowseDecompiledCode">sampleCodeToBrowseDecompiledCode	"FooClockModel sampleCodeToBrowseDecompiledCode."	| aClass aSelector aString aNode aText |	aClass := FooAnalogClockView.	aSelector := #displayTickHandOn:.	aString := (aClass compiledMethodAt: aSelector) decompiledSource.	aNode := Refactory.Browser.RBParser parseMethod: aString.	aText := aNode formattedCode asText makeSelectorBoldIn: aClass.	TextEditorView		edit: (ValueHolder with: aText)		label: 'Decompiled Code'		icon: nil		extent: 600 @ 400</body>
</methods>

<methods>
<class-id>FooClockModel class</class-id> <category>interface specs</category>

<body package="Foo-Clock" selector="windowSpecAnalog">windowSpecAnalog	"UIPainter new openOnClass: self andSelector: #windowSpecAnalog"	&lt;resource: #canvas&gt;	^#(#FullSpec 		#window: 		#(#WindowSpec 			#label: 			#(#UserMessage 				#key: #jun_Analog_Clock_MVC 				#defaultString: 'Analog Clock MVC' ) 			#min: #(#Point 120 120 ) 			#bounds: #(#Rectangle 100 100 220 220 ) 			#isEventDriven: true ) 		#component: 		#(#SpecCollection 			#collection: #(				#(#ArbitraryComponentSpec 					#layout: #(#LayoutFrame 1 0 1 0 -1 1 -1 1 ) 					#component: #createAnalogView ) ) ) )</body>

<body package="Foo-Clock" selector="windowSpec">windowSpec	"UIPainter new openOnClass: self andSelector: #windowSpec"	&lt;resource: #canvas&gt;	^#(#FullSpec 		#window: 		#(#WindowSpec 			#label: 			#(#UserMessage 				#key: #jun_Clock 				#defaultString: 'Clock' ) 			#min: #(#Point 120 120 ) 			#bounds: #(#Rectangle 100 100 220 220 ) 			#isEventDriven: true ) 		#component: 		#(#SpecCollection 			#collection: #(				#(#ArbitraryComponentSpec 					#layout: #(#LayoutFrame 1 0 1 0 -1 1 -1 1 ) 					#component: #createView ) ) ) )</body>

<body package="Foo-Clock" selector="windowSpecDigital">windowSpecDigital	"UIPainter new openOnClass: self andSelector: #windowSpecDigital"	&lt;resource: #canvas&gt;	^#(#FullSpec 		#window: 		#(#WindowSpec 			#label: 			#(#UserMessage 				#key: #jun_Digital_Clock_MVC 				#defaultString: 'Digital ClockMVC' ) 			#min: #(#Point 120 60 ) 			#bounds: #(#Rectangle 100 100 220 160 ) 			#isEventDriven: true ) 		#component: 		#(#SpecCollection 			#collection: #(				#(#ArbitraryComponentSpec 					#layout: #(#LayoutFrame 1 0 1 0 -1 1 -1 1 ) 					#component: #createDigitalView ) ) ) )</body>
</methods>

<methods>
<class-id>FooClockModel class</class-id> <category>examples</category>

<body package="Foo-Clock" selector="example2">example2	"FooClockModel example2."	| aClock |	aClock := FooClockModel new.	aClock openInterface: #windowSpecDigital.	^aClock</body>

<body package="Foo-Clock" selector="example3">example3	"FooClockModel example3."	| aModel aPoint |	aModel := FooClockModel new.	aPoint := 50 @ 80.	aModel openAt: aPoint interface: #windowSpecAnalog.	aPoint := aModel getWindow displayBox bottomLeft + (0 @ 28).	aModel openAt: aPoint interface: #windowSpecDigital.	^aModel</body>

<body package="Foo-Clock" selector="example1">example1	"FooClockModel example1."	| aClock |	aClock := FooClockModel new.	aClock openInterface: #windowSpecAnalog.	^aClock</body>
</methods>


<methods>
<class-id>FooClockModel</class-id> <category>processing</category>

<body package="Foo-Clock" selector="resumeClockProcess">resumeClockProcess	clockProcess notNil ifTrue: [self terminateClockProcess].	clockProcess := 			[self				assert: [self yourself]				do: 					[[true] whileTrue: 							[self changed.							(Delay untilMilliseconds: self nextMillisecondClockValue) wait]]				ensure: [self terminateClockProcess]]					newProcess.	clockProcess priority: Processor activeProcess priority + 1.	clockProcess resume</body>

<body package="Foo-Clock" selector="terminateClockProcess">terminateClockProcess	clockProcess notNil ifTrue: [clockProcess terminate].	clockProcess := nil</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>accessing</category>

<body package="Foo-Clock" selector="currentDateString">currentDateString	^JunCalendarModel stringFromDate , ' ('		, (JunCalendarDateModel new weekdayNames at: self currentDate weekdayIndex) , ')'</body>

<body package="Foo-Clock" selector="currentTimeString">currentTimeString	^JunCalendarModel stringFromTime</body>

<body package="Foo-Clock" selector="currentTime">currentTime	^Time now</body>

<body package="Foo-Clock" selector="currentDate">currentDate	^Date today</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>private</category>

<body package="Foo-Clock" selector="nextMillisecondClockValue">nextMillisecondClockValue	^Time millisecondClockValue + 1000 truncateTo: 1000</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>defaults</category>

<body package="Foo-Clock" selector="defaultViewClass">defaultViewClass	^FooClockView</body>

<body package="Foo-Clock" selector="defaultWindowLabel">defaultWindowLabel	^nil</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>interface closing</category>

<body package="Foo-Clock" selector="noticeOfWindowClose:">noticeOfWindowClose: aWindow	super noticeOfWindowClose: aWindow.	self terminateClockProcess</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>interface opening</category>

<body package="Foo-Clock" selector="createAnalogView">createAnalogView	| aView |	aView := FooAnalogClockView new.	aView model: self.	^aView</body>

<body package="Foo-Clock" selector="createDigitalView">createDigitalView	| aView |	aView := FooDigitalClockView new.	aView model: self.	^aView</body>
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>initialize-release</category>

<body package="Foo-Clock" selector="release">release	super release.	self terminateClockProcess</body>

<body package="Foo-Clock" selector="initialize">initialize	super initialize.	self resumeClockProcess</body>
</methods>


<methods>
<class-id>FooDigitalClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="flushCache">flushCache	cachedStyle := nil</body>

<body package="Foo-Clock" selector="cachedStyle">cachedStyle	cachedStyle		ifNil: 			[| bold height text |			bold := self model currentTimeString asText allBold.			height := self bounds height - 10.						[cachedStyle := JunFontModel textStyleHeight: height.			text := ComposedText withText: bold style: cachedStyle.			height &gt; 14 and: [text bounds width &gt; (self bounds width - 10)]]					whileTrue: [height := height - 2]].	^cachedStyle</body>
</methods>

<methods>
<class-id>FooDigitalClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext	| bold text |	self isOpen ifFalse: [^nil].	self clearInside.	bold := self model currentTimeString asText allBold.	text := ComposedText withText: bold style: self cachedStyle.	text displayOn: graphicsContext at: self bounds center - text bounds center</body>
</methods>


<methods>
<class-id>FooAnalogClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="rotateBlock">rotateBlock	| aBlock |	aBlock :=			[:point :degrees |			| radians sin cos x y |			radians := degrees negated degreesToRadians.			sin := radians sin.			cos := radians cos.			x := point x * cos + (point y * sin).			y := point x * sin negated + (point y * cos).			x @ y].	^aBlock</body>

<body package="Foo-Clock" selector="flushCache">flushCache	cachedImage := nil.	cachedTime := nil</body>
</methods>

<methods>
<class-id>FooAnalogClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayBackgroundImageOn:">displayBackgroundImageOn: graphicsContext	| center radius box |	graphicsContext		paint: self backgroundColor;		displayRectangle: self bounds;		paint: self foregroundColor.	center := self bounds center.	radius := self bounds extent // 2 - 12.	box := 0 @ 0 extent: 2 @ 2.	1 to: 12		do: 			[:number |			| text degrees x y |			text := ComposedText withText: number printString asText.			degrees := (number - 3) * 30.			x := degrees degreesToRadians cos.			y := degrees degreesToRadians sin.			text displayOn: graphicsContext at: (center + 1 + (x @ y * radius) - (text extent // 2)) rounded.			graphicsContext displayRectangle: box at: (center + (x @ y * (radius - 10))) rounded]</body>

<body package="Foo-Clock" selector="displayLongHandOn:">displayLongHandOn: graphicsContext	| center radius minutes x y block points |	center := self bounds center.	radius := self bounds extent // 2 - 20.	minutes := cachedTime minutes.	x := (minutes * 6 - 90) degreesToRadians cos.	y := (minutes * 6 - 90) degreesToRadians sin.	block := self rotateBlock.	points := Array new: 5.	points at: 1 put: center + (block value: x @ y * 3 asPoint value: -180).	points at: 2 put: center + (block value: x @ y * 3 asPoint value: -90).	points at: 3 put: center + (x @ y * (radius * 9 // 10) asPoint).	points at: 4 put: center + (block value: x @ y * 3 asPoint value: 90).	points at: 5 put: points first copy.	points := points collect: [:p | p rounded].	graphicsContext		paint: self selectionForegroundColor;		lineWidth: 1;		displayPolygon: points;		paint: self selectionBackgroundColor;		displayPolyline: points</body>

<body package="Foo-Clock" selector="displayTickHandOn:">displayTickHandOn: graphicsContext	| center radius length seconds x y |	center := self bounds center.	radius := self bounds extent // 2 - 20.	length := radius * 10 // 10.	seconds := cachedTime seconds.	x := (seconds * 6 - 90) degreesToRadians cos.	y := (seconds * 6 - 90) degreesToRadians sin.	graphicsContext		paint: self selectionForegroundColor;		lineWidth: 1;		displayLineFrom: center to: (center + (x @ y * length)) rounded</body>

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext	((cachedImage isNil or: [cachedTime isNil])		or: [self model currentTime minutes ~= cachedTime minutes])			ifTrue: 				[| aPixmap pixmapContext |				cachedTime := self model currentTime.				self					assert: [aPixmap := Pixmap extent: self bounds extent]					do: 						[Cursor execute showWhile: 								[pixmapContext := aPixmap graphicsContext.								self									displayBackgroundImageOn: pixmapContext;									displayShortHandOn: pixmapContext;									displayLongHandOn: pixmapContext.								cachedImage := aPixmap asImage]]					ensure: [aPixmap close]]			ifFalse: [cachedTime := self model currentTime].	cachedImage displayOn: graphicsContext.	self displayTickHandOn: graphicsContext</body>

<body package="Foo-Clock" selector="displayShortHandOn:">displayShortHandOn: graphicsContext	| center radius minutes hours x y block points |	center := self bounds center.	radius := self bounds extent // 2 - 20.	minutes := cachedTime minutes.	hours := cachedTime hours * 5 + (minutes / 12).	x := (hours * 6 - 90) degreesToRadians cos.	y := (hours * 6 - 90) degreesToRadians sin.	block := self rotateBlock.	points := Array new: 5.	points at: 1 put: center + (block value: x @ y * 3 asPoint value: -180).	points at: 2 put: center + (block value: x @ y * 3 asPoint value: -90).	points at: 3 put: center + (x @ y * (radius * 7 // 10) asPoint).	points at: 4 put: center + (block value: x @ y * 3 asPoint value: 90).	points at: 5 put: points first copy.	points := points collect: [:p | p rounded].	graphicsContext		paint: self selectionForegroundColor;		lineWidth: 1;		displayPolygon: points;		paint: self selectionBackgroundColor;		displayPolyline: points</body>
</methods>



</st-source>
