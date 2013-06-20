ANT	= env LC_ALL=en ant

all:
	$(ANT) all

clean:
	$(ANT) clean

test: all
#	$(ANT) test
	java -Dfile.encoding=UTF-8 -Xmx512m -Xss1024k -jar primeministers.jar

install:
	$(ANT) install

doc:
	$(ANT) doc

zip:
	$(ANT) zip
