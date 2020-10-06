# given the head pointer we need to return the linked list  after making the following changes
# swap every alternate value with its neighbour 
# for example INPUT : node = 0 → 1 → 3 → 4 → 5 → 6 → 7 → 8 → 9
# OUTPUT : node = 1 → 0 → 4 → 3 → 6 → 5 → 8 → 7 → 9

def PairWiseSwap(node):
  data=-1
  if node==None or node.next==None:
      return node
  temp=node
  switch=True
  while temp.next!=None:
      if switch:
          data=temp.val
          temp.val=temp.next.val
      else:
          temp.val=data
      temp=temp.next
      switch =not switch
  if not switch:
      temp.val=data
  return node
