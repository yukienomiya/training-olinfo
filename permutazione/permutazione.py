def permutazione(k):
  alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
  i, j = 0, 25
  res = ''
  leftEnd = False
  for idx in range(k // 2):
    res += alphabet[i] + alphabet[j]
    i += 1
    j -= 1
  if k % 2:
    res += alphabet[i]
    i += 1
    leftEnd = True
  if leftEnd:
    for idx in range(i, j + 1):
      res += alphabet[idx]
  else:
    for idx in range(j, i - 1, -1):
      res += alphabet[idx]
  return res

print(permutazione(3))