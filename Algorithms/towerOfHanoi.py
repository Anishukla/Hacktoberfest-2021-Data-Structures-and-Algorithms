"""
Author: @lx5321
"""

class Tower:
  def __init__(self):
        self.counter = 0
  
  """
  PARAMETERS:
  n: number of rings.
  org: origin of ring.
  aux: auxilary ring / intermediate ring.
  dst: destination ring.
  """

  def hanoi(self, n, org, aux, dst):
    if n == 1: 
       self.counter += 1
       print('{0} moved -> {1}'.format(org, dst))
    else:
       self.hanoi(n-1, org, dst, aux)
       self.hanoi(1, org, aux, dst)
       self.hanoi(n-1, aux, org, dst)

# create object
tower = Tower()

# call method
tower.hanoi(3, "Origin", "Auxilliary", "Destination")
