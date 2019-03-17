import ctypes

lib = ctypes.cdll.LoadLibrary('./_fib.so')

class fib(object):

    def __init__(self, val):
        lib.Libmath_new.argtypes = [ctypes.c_int]
        lib.Libmath_new.restype = ctypes.c_void_p

        lib.Libmath_cfib.argtypes = [ctypes.c_void_p]
        lib.Libmath_cfib.restype = ctypes.c_double

        self.obj = lib.Libmath_new(val)

    def cfib(self):
        return lib.Libmath_cfib(self.obj)


if __name__ == '__main__':
    s = fib(10)
    print(s.cfib())

