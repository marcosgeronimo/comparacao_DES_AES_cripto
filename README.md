# Comparação_DES_AES_cripto

####  INTRODUÇÃO
Vamos comparar dois códigos de criptografia: um usando DES (Data Encryption Standard) muito utilizado ate o ano de 2001, porém ainda presente nos dias de atuais. 
E outro usando AES (Advanced Encryption Standard), uma atualização iniciada em 2001, para substituição do DES, após o avanço na tecnologia, ainda centenas de milhares seguem sem atualização.


#### Abaixo inseri os dois códigos com a mesma funcionalidade para exemplificação.

#### CÓDIGO_DES (main_DES.c)

![image](https://github.com/user-attachments/assets/ef85bb78-72ec-4fee-9b6f-5823a9d93d6a)

##### PROBLEMA DE SEGURANÇA 
Algoritmos DES é considerado inseguro para uso moderno devido ao seu tamanho de chave de 56 bits, que é vulnerável a ataques de força bruta.

##### MODO DE OPERAÇÃO 
O código não especifica um modo de operação, o que implica que o ECB (Electronic Codebook) está sendo usado, o tornando vulnerável à exposição de padrões.

##### PERMUTAÇÃO MANUAL E CHAVE
A implementação manual das funções de permutação e configuração de chaves pode conter erros e não segue as práticas recomendadas de segurança.

##### CONCLUSÃO
Este código é inadequado para uso em sistemas modernos devido às vulnerabilidades conhecidas do DES e à falta de modos de operação seguros.






#### CÓDIGO_AES (main.AES.c)

![image](https://github.com/user-attachments/assets/f0306dcd-2a47-49e5-bf46-7f08ca9250cd)


##### MELHORIAS E SEGURANÇA
Algoritmo AES é o padrão atual para criptografia simétrica, com suporte para chaves de 128, 192 e 256 bits, oferecendo uma segurança muito maior.

##### MODO DE OPERAÇÃO
Embora o código use ECB por padrão, ele pode ser facilmente adaptado para usar modos mais seguros, como CBC ou GCM.

##### MANUSEIO DE BLOCOS E PADDING
O código lida com blocos incompletos, garantindo que o plaintext seja tratado corretamente.

##### BIBLIOTECAS SEGURAS
O código utiliza a biblioteca OpenSSL para operações criptográficas, garantindo conformidade com as melhores práticas de segurança.

##### CONCLUSÃO
Este código é muito mais seguro do que a implementação DES, mas ainda precisa ser ajustado para evitar o uso do modo ECB. 
Usar AES com um modo de operação seguro é recomendado para aplicações modernas.




### COMPARAÇÃO GERAL

![image](https://github.com/user-attachments/assets/1a845b03-2d0e-4d47-9cfa-823fa8b90bee)


##### SUGESTÕES BAIXO

EVITAR DES - Não use DES em novos projetos. Migre para AES ou outros algoritmos modernos.

EVITAR ECB - Use modos de operação como CBC ou GCM para evitar vulnerabilidades associadas ao modo ECB.

BIBLIOTECAS SEGURAS - Sempre que possível, use bibliotecas bem testadas, como OpenSSL, para evitar erros de implementação.


##### CONCLUSÃO
O código AES oferece uma base muito mais segura para criptografia simétrica do que o código DES. 
No entanto, para maximizar a segurança, o AES deve ser usado com modos de operação seguros e padding apropriado.



