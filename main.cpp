#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// #define tam 9
const int tam = 9;

using namespace std;

void imprimirMatriz(int matriz[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    bool loop = true;
    int op, mat[tam][tam] = {4,9,5,2,8,7,3,6,1,7,2,8,6,1,3,4,9,5,3,6,1,9,5,4,7,2,8,6,5,3,8,4,9,2,1,7,9,8,4,1,7,2,6,5,3,2,1,7,5,3,6,9,8,4,1,3,2,4,6,5,8,7,9,5,4,6,7,9,8,1,3,2,8,7,9,3,2,1,5,4,6}, i, j, matgab[tam][tam] = {0}, matGabPreenchida[tam][tam] = {0}, temp, num;
    int escondeNumMatriz[2], cont = 1, indiceLinha = 1, quantLoop = 9, linha, coluna, valor;
    int contLinha = 0, contColuna = 0, contQ1 = 0, contQ2 = 0, contQ3 = 0, contQ4 = 0, contQ5 = 0, contQ6 = 0, contQ7 = 0, contQ8 = 0, contQ9 = 0, k;
    bool endGame = true;

    do{
        system("cls");
        cout << " ____                  __             __                  " << endl;
        cout << "/\\  _`\\               /\\ \\           /\\ \\                 " << endl;
        cout << "\\ \\,\\L\\_\\    __  __   \\_\\ \\     ___  \\ \\ \\/'\\    __  ""__  " << endl;
        cout << " \\/_\\__ \\   /\\ \\/\\ \\  /'_` \\   / __`\\ \\ \\ , <   /\\ ""\\/\\ \\ " << endl;
        cout << "   /\\ \\L\\ \\ \\ \\ \\_\\ \\/\\ \\L\\ \\ /\\ \\L\\ \\ \\ \\ ""\\\\`\\ \\ \\ \\_\\ \\" << endl;
        cout << "   \\ `\\____\\ \\ \\____/\\ \\___,_\\\\ \\____/  \\ \\_\\ \\_\\ ""\\ \\____/" << endl;
        cout << "    \\/_____/  \\/___/  \\/__,_ / \\/___/    \\/_/\\/_/ \\/___/ " << endl;

        cout << "\n\n1 - Jogar\n2 - Sobre\n3 - Sair";

        cout << "\n\nEscolha uma opção: ";
        cin >> op;

        switch(op){
            case 1:
                system("cls");
                imprimirMatriz(mat);
                cout << "\n";

                // num = (rand() % 4) + 1;
                num = 4;

                switch(num){
                case 1:
                    for(i = 0; i < tam; i++){
                        for(j = 0; j < tam; j++){
                            matgab[i][j] = mat[i][j];
                        }   
                    }
                break;

                case 2:
                    for(i = 0; i < tam; i++){
                        for(j = 0; j < tam; j++){
                            matgab[j][i] = mat[i][j];
                        }   
                    }
                break;

                case 3:
                    for (i = 0; i < tam; i++) {
                        // Armazena a linha atual em um vetor temporário
                        for (j = 0; j < tam; j++) {
                            temp = mat[i][j];
                            matgab[i][j] = mat[tam-i-1][j];
                            mat[tam-i-1][j] = temp;
                        }
                    }
                break;

                case 4:
                    for (i = 0; i < tam; i++) {
                        // Armazena a linha atual em um vetor temporário
                        for (j = 0; j < tam; j++) {
                            temp = mat[i][j];
                            matgab[i][j] = mat[i][tam-j-1];
                            mat[i][tam-j-1] = temp;
                        }
                    }
                break;
                }

                cout << num << "\n\n";

                imprimirMatriz(matgab);

                while(quantLoop > 0){
                    // Aqui pego um número de 1 a 9 e determino quantas vezes ele vai ser escondido para formar o sudoku
                    for(i = 0; i < 2; i++){
                        escondeNumMatriz[i] = (rand() % 9) + 1;
                    }

                    // Aqui eu vou mascarar a matriz sudoku
                    for(i = 0; i < tam; i++){
                        for(j = 0; j < tam; j++){
                            // Procura elementos cuja caia na lógica e esconde apenas a quantidade determinada
                            if(matgab[i][j] == escondeNumMatriz[0] && cont <= 2){
                                matgab[i][j] = 0;
                                cont++;
                            }
                        }
                    }
                    cont = 1;
                    quantLoop--;
                }

                quantLoop = 9;

                // Aqui eu alimento eu duplico a matriz que será preenchida
                for(i = 0; i < tam; i++){
                    for(j = 0; j < tam; j++){
                        matGabPreenchida[i][j] = matgab[i][j];
                    }
                }

                // Aqui começa a preencher os termos do jogo
                do{
                    indiceLinha = 1, contLinha = 0, contColuna = 0, contQ1 = 0, contQ2 = 0, contQ3 = 0, contQ4 = 0, contQ5 = 0, contQ6 = 0, contQ7 = 0, contQ8 = 0, contQ9 = 0;
                    system("cls");
                    // Imprimindo a matriz mascarada
                    cout << "\n     1  2  3  4  5  6  7  8  9" << endl; //Imprimindo o índice das colunas
                    cout << "     ------------------------" << endl;
                    cout << "     ------------------------" << endl;
                    for(i = 0; i < tam; i++){
                        cout << indiceLinha << " " << "||";
                        indiceLinha++;

                        for(j = 0; j < tam; j++){
                            if(matGabPreenchida[i][j] == 0){
                                cout << " " << " " << " ";
                            } else{
                                cout << " " << matGabPreenchida[i][j] << " ";
                            }
                        }
                        cout << "||" << endl;
                    }

                    cout << "     -----------------------" << endl;

                    cout << "\nDigite a linha: ";
                    cin >> linha;

                    while(linha < 1 || linha > 9){
                        cout << "\nDigite um valor para a linha entre 1 e 9!";
                        cout << "\nDigite a linha: ";
                        cin >> linha;
                    }

                    cout << "\nDigite a coluna: ";
                    cin >> coluna;

                    while(coluna < 1 || coluna > 9){
                        cout << "\nDigite um valor para a coluna entre 1 e 9!";
                        cout << "\nDigite a coluna: ";
                        cin >> coluna;
                    }

                    cout << "\nDigite o valor: ";
                    cin >> valor;

                    while(valor < 1 || valor > 9){
                        cout << "\nDigite um valor para a valor entre 1 e 9!";
                        cout << "\nDigite o valor: ";
                        cin >> valor;
                    }

                    if(matGabPreenchida[linha-1][coluna-1] == 0 || matgab[linha-1][coluna-1] != matGabPreenchida[linha-1][coluna-1]){
                        matGabPreenchida[linha-1][coluna-1] = valor;
                    } else {
                        cout << "\nNão pode alterar" << endl;
                        system("pause");
                    }

                    // Verifico se a matriz está completa
                    cont = 0;

                    for(i = 0; i < tam; i++){
                        for(j = 0; j < tam; j++){
                            if(matGabPreenchida[i][j] != 0){
                                cont++;
                            }
                        }
                    }

                    if(cont == 81){
                        endGame = false;
                    }

                }while(endGame);

                // Verifico se o jogo foi preenchido corretamente
                for(i = 0; i < tam; i++){
                    for(k = 0; k < tam-1; k++){
                        for(j = k; j < tam-1; j++){
                            // Contando numeros das linhas
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contLinha++;
                            }

                            // Contando numeros das colunas
                            if(matGabPreenchida[k][i] != matGabPreenchida[j+1][i]){
                                contColuna++;
                            }
                        }
                    }
                }

                // Aqui verifico cada quadrante... dor dor
                // Q1
                for(i = 0; i < 3; i++){
                    for(k = 0; k < 2; k++){
                        for(j = k; j < 2; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ1++;
                            }
                            if(matGabPreenchida[k][i] != matGabPreenchida[j+1][i]){
                                contQ1++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q2 - Linha
                for(i = 0; i < 3; i++){
                    for(k = 3; k < 5; k++){
                        for(j = k; j < 5; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ2++;
                            }
                        }
                    }
                }

                // Q2 - Coluna
                for(j = 3; j < 6; j++){
                    for(k = 0; k < 2; k++){
                        for(i = k; i < 2; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ2++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q3 - Linha
                for(i = 0; i < 3; i++){
                    for(k = 6; k < 8; k++){
                        for(j = k; j < 8; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ3++;
                            }
                        }
                    }
                }

                // Q3 - Coluna
                for(j = 6; j < 9; j++){
                    for(k = 0; k < 2; k++){
                        for(i = k; i < 2; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ3++;
                            }
                        }
                    }
                }
                
                // ---------------------------

                // Q4 - Linha
                for(i = 3; i < 6; i++){
                    for(k = 0; k < 2; k++){
                        for(j = k; j < 2; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ4++;
                            }
                        }
                    }
                }

                // Q4 - Coluna
                for(j = 0; j < 3; j++){
                    for(k = 3; k < 5; k++){
                        for(i = k; i < 5; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ4++;
                            }
                        }
                    }
                }
                
                // ---------------------------

                // Q5
                for(i = 3; i < 6; i++){
                    for(k = 3; k < 5; k++){
                        for(j = k; j < 5; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ5++;
                            }
                            if(matGabPreenchida[k][i] != matGabPreenchida[j+1][i]){
                                contQ5++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q6 - Linha
                for(i = 3; i < 6; i++){
                    for(k = 6; k < 8; k++){
                        for(j = k; j < 8; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ6++;
                            }
                        }
                    }
                }

                // Q6 - Coluna
                for(j = 6; j < 9; j++){
                    for(k = 3; k < 5; k++){
                        for(i = k; i < 5; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ6++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q7 - Linha
                for(i = 6; i < 9; i++){
                    for(k = 0; k < 2; k++){
                        for(j = k; j < 2; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ7++;
                            }
                        }
                    }
                }

                // Q7 - Coluna
                for(j = 0; j < 3; j++){
                    for(k = 6; k < 8; k++){
                        for(i = k; i < 8; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ7++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q8 - Linha
                for(i = 6; i < 9; i++){
                    for(k = 3; k < 5; k++){
                        for(j = k; j < 5; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ8++;
                            }
                        }
                    }
                }

                // Q8 - Coluna
                for(j = 3; j < 6; j++){
                    for(k = 6; k < 8; k++){
                        for(i = k; i < 8; i++){
                            if(matGabPreenchida[k][j] != matGabPreenchida[i+1][j]){
                                contQ8++;
                            }
                        }
                    }
                }

                // ---------------------------

                // Q9
                for(i = 6; i < 9; i++){
                    for(k = 6; k < 8; k++){
                        for(j = k; j < 8; j++){
                            if(matGabPreenchida[i][k] != matGabPreenchida[i][j+1]){
                                contQ9++;
                            }
                            if(matGabPreenchida[k][i] != matGabPreenchida[j+1][i]){
                                contQ9++;
                            }
                        }
                    }
                }

                // 324 = numero de vezes que vai ser comparado
                if(contLinha == 324 && contColuna == 324 && contQ1 == 18 && contQ2 == 18 && contQ3 == 18 && contQ4 == 18 && contQ5 == 18 && contQ6 == 18 && contQ7 == 18 && contQ8 == 18 && contQ9 == 18){
                    // win = true;
                    cout << "\n\nParabens! Voce ganhou!" << endl;
                } else{
                    // win = false;
                    cout << "\nIhhh vacilao, errou algum ali" << endl;
                }

                system("pause");
            break;

            case 2:
                system("cls");
                cout << "\t-=-=-=-=--=-=-Sobre-=-=-=-=--=-=-" << endl;
                cout << "\nIntegrantes do grupo" << endl;
                cout << "\n1 - Artur\n2 - Lucas Cauã Silva da Cruz\n3 - Pedro Quioca\n4 - ............" << endl;

                cout << "\nAbril/2023" << endl;

                cout << "\nNome do professor: ....................." << endl;

                system("pause");
            break;

            case 3:
                system("cls");
                cout << "\n\nInfelizmente você saiu do jogo! Jogue novamente quando quiser!" << endl;
                loop = false;
            break;

            default:
                cout << "\n\nEscolha uma opção válida!" << endl;
                system("pause");
                system("cls");
            break;
        }
    }while(loop);

    return 0;
}