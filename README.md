# W.O.P.R.
## War Operational Planning and Response

A simple and unfinished pet project from a fan of the movie [War Games](http://www.imdb.com/title/tt0086567/).
Primarily supposed to be a simulator of the WOPR from the movie War games. Written in C.

### Update
It's been almost a year since working on this last and I have gone back and seen the ugliness of the code.
Please do not judge me.

My younger self decided to over-engineer a lot of things like this:

```C
/**                                                                               
 * @brief Check Variable                                                          
 * @details Checks if the variable and                                            
 *          the code value are the same.                                          
 *                                                                                
 * @param n code value in.                                                        
 * @param v variable in.                                                          
 *                                                                                
 * @return 0 = y, 1 = no.                                                         
 */                                                                              
int chkVar(char n, char v){                                                       
        if (n == v){                                                          
                return 0;                                                         
        } else {                                                                  
                return 1;                                                         
        }                                                                         
}
```
WHY DID I DO THIS? D:<