class Solution {
    public String restoreString(String s, int[] indices) {
        
        char ch[] = new char[indices.length];
        int n = indices.length;
        for(int i=0;i<n;i++)
        {
            
            ch[indices[i]]=s.charAt(i);  
           
        }
        String f= new String(ch);
        
        return f;
        
    }
}
