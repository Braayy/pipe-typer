install: typer
	mv typer /usr/bin/

typer:
	gcc main.c -o typer -lX11 -lXtst

clean:
	rm -f typer
