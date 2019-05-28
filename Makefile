############################################
#
# Regex Test
#   copyright 2019.05.28 konoar
#
############################################

TARGETBIN := ./test

.PHONY: clean run

run: $(TARGETBIN)
	@-$(TARGETBIN)

clean:
	@-rm ./*.o $(TARGETBIN)

$(TARGETBIN): main.o
	@gcc -o $(TARGETBIN) $^

%.o: %.c
	@gcc -o $@ -c $^

