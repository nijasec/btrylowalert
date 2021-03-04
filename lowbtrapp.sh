#! /bin/sh

### BEGIN INIT INFO
# Provides:          fan.o
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
### END INIT INFO

# Carry out specific functions when asked to by the system
case "$1" in
  start)
    echo "Starting lowbtrapp.o"
    /usr/local/bin/lowbtrapp.o &
    ;;
  stop)
    echo "Stopping app"
    pkill -f /usr/local/bin/lowbtrapp.o
    ;;
  *)
    echo "Usage: /etc/init.d/lowbtrapp.sh {start|stop}"
    exit 1
    ;;
esac

exit 0
