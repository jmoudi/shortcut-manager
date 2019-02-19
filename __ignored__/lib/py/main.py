from assign_keybinds import assign
from timeit import timeit

main = assign

start_msg = """===========================================================
START main_timer
"""
end_msg = """===========================================================
END main_timer: 
"""

def test(testfunc):
    print(start_msg)
    main_timer = timeit(stmt=testfunc, number=1)
    print(end_msg, main_timer)

test(main)