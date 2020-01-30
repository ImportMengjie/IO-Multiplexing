import threading
import itertools
import time
import sys


class Signal:
    go = True


def spin(msg, singal):
    write, flush = sys.stdout.write, sys.stdout.flush
    for char in itertools.cycle('|/-\\'):
        status = char + ' '+msg
        write(status)
        flush()
        write('\x08'*len(status))
        time.sleep(1)
        if not Signal.go:
            break
    write(' '*len(status)+'\x08'*len(status))


def slow_function():
    time.sleep(3)
    return 0


def supervisor():
    spinner = threading.Thread(target=spin, args=('thinking?', Signal))
    # print('spinner object:', spinner)
    spinner.start()
    result = slow_function()
    Signal.go = False
    spinner.join()
    return result


if __name__ == '__main__':
    supervisor()
