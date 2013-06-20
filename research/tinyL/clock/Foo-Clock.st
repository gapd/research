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
<body>Programming Language (AOKI Atsushi)
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
<body>Programming Language (AOKI Atsushi)
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
<body>Programming Language (AOKI Atsushi)
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
<body>Programming Language (AOKI Atsushi)
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
<body>Programming Language (AOKI Atsushi)
</comment>

<methods>
<class-id>FooClockView</class-id> <category>display box accessing</category>

<body package="Foo-Clock" selector="bounds:">bounds: ignore
</methods>

<methods>
<class-id>FooClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="flushCache">flushCache
</methods>

<methods>
<class-id>FooClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext

<body package="Foo-Clock" selector="displayOn:">displayOn: graphicsContext
</methods>

<methods>
<class-id>FooClockView</class-id> <category>initialize-release</category>

<body package="Foo-Clock" selector="initialize">initialize
</methods>

<methods>
<class-id>FooClockView</class-id> <category>visual properties</category>

<body package="Foo-Clock" selector="selectionBackgroundColor">selectionBackgroundColor

<body package="Foo-Clock" selector="selectionForegroundColor">selectionForegroundColor
</methods>

<methods>
<class-id>FooClockView</class-id> <category>updating</category>

<body package="Foo-Clock" selector="update:">update: aspectSymbol
</methods>

<methods>
<class-id>FooClockView</class-id> <category>controller accessing</category>

<body package="Foo-Clock" selector="defaultControllerClass">defaultControllerClass
</methods>


<methods>
<class-id>FooClockController</class-id> <category>control defaults</category>

<body package="Foo-Clock" selector="yellowButtonActivity">yellowButtonActivity

<body package="Foo-Clock" selector="redButtonActivity">redButtonActivity
</methods>


<methods>
<class-id>FooClockModel class</class-id> <category>tips</category>

<body package="Foo-Clock" selector="sampleCodeToBrowseSourceCode">sampleCodeToBrowseSourceCode

<body package="Foo-Clock" selector="saveAsFooAndExercise">saveAsFooAndExercise

<body package="Foo-Clock" selector="sampleCodeToBrowseDecompiledCode">sampleCodeToBrowseDecompiledCode
</methods>

<methods>
<class-id>FooClockModel class</class-id> <category>interface specs</category>

<body package="Foo-Clock" selector="windowSpecAnalog">windowSpecAnalog

<body package="Foo-Clock" selector="windowSpec">windowSpec

<body package="Foo-Clock" selector="windowSpecDigital">windowSpecDigital
</methods>

<methods>
<class-id>FooClockModel class</class-id> <category>examples</category>

<body package="Foo-Clock" selector="example2">example2

<body package="Foo-Clock" selector="example3">example3

<body package="Foo-Clock" selector="example1">example1
</methods>


<methods>
<class-id>FooClockModel</class-id> <category>processing</category>

<body package="Foo-Clock" selector="resumeClockProcess">resumeClockProcess

<body package="Foo-Clock" selector="terminateClockProcess">terminateClockProcess
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>accessing</category>

<body package="Foo-Clock" selector="currentDateString">currentDateString

<body package="Foo-Clock" selector="currentTimeString">currentTimeString

<body package="Foo-Clock" selector="currentTime">currentTime

<body package="Foo-Clock" selector="currentDate">currentDate
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>private</category>

<body package="Foo-Clock" selector="nextMillisecondClockValue">nextMillisecondClockValue
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>defaults</category>

<body package="Foo-Clock" selector="defaultViewClass">defaultViewClass

<body package="Foo-Clock" selector="defaultWindowLabel">defaultWindowLabel
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>interface closing</category>

<body package="Foo-Clock" selector="noticeOfWindowClose:">noticeOfWindowClose: aWindow
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>interface opening</category>

<body package="Foo-Clock" selector="createAnalogView">createAnalogView

<body package="Foo-Clock" selector="createDigitalView">createDigitalView
</methods>

<methods>
<class-id>FooClockModel</class-id> <category>initialize-release</category>

<body package="Foo-Clock" selector="release">release

<body package="Foo-Clock" selector="initialize">initialize
</methods>


<methods>
<class-id>FooDigitalClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="flushCache">flushCache

<body package="Foo-Clock" selector="cachedStyle">cachedStyle
</methods>

<methods>
<class-id>FooDigitalClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext
</methods>


<methods>
<class-id>FooAnalogClockView</class-id> <category>private</category>

<body package="Foo-Clock" selector="rotateBlock">rotateBlock

<body package="Foo-Clock" selector="flushCache">flushCache
</methods>

<methods>
<class-id>FooAnalogClockView</class-id> <category>displaying</category>

<body package="Foo-Clock" selector="displayBackgroundImageOn:">displayBackgroundImageOn: graphicsContext

<body package="Foo-Clock" selector="displayLongHandOn:">displayLongHandOn: graphicsContext

<body package="Foo-Clock" selector="displayTickHandOn:">displayTickHandOn: graphicsContext

<body package="Foo-Clock" selector="displayTimeOn:">displayTimeOn: graphicsContext

<body package="Foo-Clock" selector="displayShortHandOn:">displayShortHandOn: graphicsContext
</methods>



</st-source>