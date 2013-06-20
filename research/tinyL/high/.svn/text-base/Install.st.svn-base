| filenameString commentString bundleNameSymbol packageNameString nameSpaceSymbol categoryString aDirectory aFilename aClosure |
filenameString := 'High.st'.
commentString := 'Copyright 2008-2012 KSU (Kyoto Sangyo University). All Right Reserved.'.
bundleNameSymbol := #KSU.
packageNameString := 'KSU-High'.
nameSpaceSymbol := #KSU.
categoryString := 'KSU-High'.
aDirectory := nil.
aFilename := nil.
aClosure :=
		[aDirectory := JunSystem fileInDirectoryFor: filenameString.
		aDirectory ifNil: [^nil]].
aClosure value.
aClosure :=
		[JunSystem
			comment: commentString
			bundle: bundleNameSymbol
			package: packageNameString
			nameSpace: nameSpaceSymbol
			category: categoryString].
aClosure value.
aFilename := aDirectory construct: filenameString.
aFilename exists ifFalse: [^nil].
^aFilename fileIn