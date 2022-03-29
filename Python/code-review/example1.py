import os

codes = list()
codes.append('1oit')
codes.append('1gnt')
codes.append('4nga')
codes.append('1fjs')

for i in range( 4 ):
    code = codes[i]
    
    from urllib.request import urlopen
    try:
        h = urlopen('http://files.rcsb.org/view/' + code + '.pdb').read().decode('ascii')
        
        f = open(code + ".pdb", 'w')
        
        lines = h.split(sep = "\n")
        for j in range(len(lines)):
            f.write(lines[j])
            f.write("\n")
            
        print ( "Saved to " + os.path.abspath(code + ".pdb"))
        
    except urllib.error.URLError as e:
        pass
        