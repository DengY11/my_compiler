# 注意检查每个node的初始化时的类型设置，因为是复制粘贴的，可能没有修改

# 现在做到function_call_return_value那里

literal_value -> var_ident |
                 func_ident + parameter_list
                 terminal_literal_value

parameter_list -> parameter |
                  parameter_list + , + parameter

parameter -> func_ident + parameter_list |
             var_ident |
             terminal_literal_value

可以看到parameter和 literal_value 是一样的 , 但为了
避免循环依赖，采用了这样的设计

2024.11.4
把函数声明节点写了一半

2024.11.5准确的说，函数声明是写完了的，但是其中要用到的StatList节点还在写
