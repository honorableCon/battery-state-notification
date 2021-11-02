battery-state : battery-state.o
	@gcc -o battery-state battery-state.o
battery-state.o : battery-state.c
	@gcc -c -Wall battery-state.c


install :
	@sudo mv battery-state /usr/local/bin/
	@(crontab -l && echo "* * * * *  battery-state") | crontab -
	@sudo systemctl restart cron
	@echo "installations complete"

clean :
	@rm *.o