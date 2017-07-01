#include"utils.h"
#include"Kernel.h"

std::string source = KERNEL(
kernel void square_float(const device float *In[[buffer(0)]],
                        device float *Out[[buffer(1)]],
                        uint tid [[thread_position_in_grid]]){
    Out[tid] = In[tid] * In[tid];
}
);

int main(){
    Kernel k(source);    
}
