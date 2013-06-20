TARGET	= scanner

# LINK (*.o)
LD	= gcc
LDFLAGS	= --strip-all

# COMPILE (*.c)
CC	= gcc
CCFLAGS	= -Wall -O2

# GENERATOR (*.lex)
LEX	= flex

OBJS	= lex.yy.o main.o
DEFS	= defs.h
REXP	= rexp.lex
LEXC	= lex.yy.c
JFK	= jfk.txt
SRC	= src.txt
TMP	= tmp.txt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): $(DEFS)

$(LEXC): $(REXP) $(DEFS)
	$(LEX) $(REXP)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	-rm -f $(TARGET)* $(OBJS) $(LEXC) $(TMP) *\~

jfk: all
	./$(TARGET) < $(JFK) > $(TMP)
	more $(TMP)

src: all
	./$(TARGET) < $(SRC) > $(TMP)
	more $(TMP)
