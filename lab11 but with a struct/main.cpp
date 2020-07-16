#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

struct counter 
{
    char symbols[100];
    int count[100];
    const char* input;
    counter(const char* text):input(text)
    {
        for(int i=0;i<=100;i++)
        {
            count[i]=0;
        }

        int symbols_registered = 0;
        for(int i=0;i<=strlen(input);i++)
        {
            if(symbols_registered==0)
            {
                if(input[i]!='\t' and input[i]!='\n' and input[i]!='\0')
                {
                    symbols[symbols_registered] = input[i];
                    count[symbols_registered]++;
                    symbols_registered++;
                }
            }
            else
            {
                for(int j=0;j<=symbols_registered;j++)
                {
                    if(input[i]!=symbols[j])
                    {
                        if(j==symbols_registered-1 and input[i]!=symbols[j])
                        {
                            if(input[i]!='\t' and input[i]!='\n' and input[i]!='\0')
                            {
                                symbols[symbols_registered] = input[i];
                                count[symbols_registered]++;
                                symbols_registered++;
                            }
                        }
                    }
                    else
                    {
                        count[j]++;
                        break;
                    }
                }
            }
        }
    }
    int howmany(char alfa)
    {
        for(int i=0;i<=100;i++)
        {
            if(symbols[i]==alfa)
            {
                return count[i]-1;
            }
        }
    return 0;
    }
};

int main(){
counter a("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut leo velit, maximus ac risus sed, dictum cursus nunc. Vivamus ultricies vitae libero ac maximus. Suspendisse aliquam, lectus vitae molestie pharetra, neque ligula eleifend dolor, non molestie mauris tortor eu justo. Vivamus dapibus quam ac tellus eleifend, eget malesuada eros ornare. Fusce imperdiet nibh eu urna cursus faucibus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Integer a mi vestibulum, egestas nunc in, convallis nibh. Aenean condimentum est ac placerat maximus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Praesent ultrices eleifend nisi, in finibus orci laoreet ac. Aliquam a nulla arcu. Aenean eget accumsan nibh. Etiam eleifend nulla a erat dignissim vehicula.Ut nec sem id enim bibendum mollis. Maecenas eget dolor tristique metus rhoncus placerat dapibus et velit. Nulla lectus arcu, sodales nec nulla in, condimentum ullamcorper dui. Sed sit amet dapibus metus. Aenean vel elit cursus, semper nibh quis, condimentum elit. Sed vulputate bibendum commodo. Pellentesque feugiat aliquet urna, sed placerat mauris auctor at. Praesent mauris neque, ornare et risus nec, vulputate condimentum nulla. Pellentesque tempor magna eget metus placerat aliquam porttitor a ex. Sed rutrum sapien non pharetra tristique. Mauris id tellus vitae nibh cursus tristique in a neque. Quisque id ipsum eros. Praesent eu quam a sapien cursus efficitur id eu risus.Integer a nulla et elit vehicula vestibulum. Curabitur leo leo, pretium non sapien et, lacinia varius leo. Fusce volutpat congue urna sed blandit. Suspendisse potenti. Curabitur vel nisi metus. Fusce a erat neque. Aliquam tincidunt ligula ut pulvinar faucibus. Phasellus convallis imperdiet diam, id cursus urna pellentesque vitae.Sed viverra euismod pulvinar. Lorem ipsum dolor sit amet, consectetur adipiscing elit. In hac habitasse platea dictumst. Cras ac rutrum nisi. Maecenas lacinia odio eu ligula imperdiet vehicula. Nunc lobortis erat ac mauris condimentum, ornare porttitor dui vestibulum. Aliquam volutpat ut urna et finibus. Integer nunc arcu, auctor a ipsum sed, hendrerit aliquet quam. Nulla vulputate magna eget gravida blandit. Suspendisse quis congue nibh, sed pellentesque nunc. Aenean non leo nibh. Curabitur mollis urna arcu, at molestie justo auctor et. Phasellus ullamcorper, massa et vestibulum dapibus, massa ex venenatis augue, sed feugiat odio lacus vitae lorem. Cras consectetur ligula magna, at finibus diam pellentesque a. Pellentesque molestie libero eu hendrerit egestas. Ut quis ornare risus.Fusce rutrum iaculis sem sit amet porttitor. Quisque tempor ?scelerisque tellus, a tincidunt purus imperdiet vitae. Sed scelerisque rhoncus blandit. Sed cursus, eros at elementum condimentum, metus nisi consectetur purus, ut maximus lectus mi vel mi. Ut vehicula tortor nec mollis sodales. Praesent augue turpis, pretium eget porta eu, aliquam eget metus. Nam sed ligula scelerisque, tempus diam sit amet, facilisis nibh. Suspendisse tempor, sapien sed efficitur rutrum, dui augue posuere dui, et tristique dolor justo eu tellus.  ");
cout<<a.howmany(' ');
}