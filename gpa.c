#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void){
    
    double input=0.0;
    int gpa=0;
    int gpaInput_int=0;
    double gpaInput_double=0.0;
    int gpaFirst=0;
    int n=0;
    int judge=0;
    
    
    printf("\n"); //メニュー画面
    printf("\n");
    printf("〜GPAカジノ〜\n");
    printf("\n");
    
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("  ルール\n");
    printf("    GPAを賭けよう。GPAが0になるまで何回でも引けます。あなたの望みのGPAを目指しましょう！(最大4.00)\n");
    printf("\n");
    printf("                      大当たり　GPAが 10×(賭けGPA) だけ戻ってきます。\n");
    printf("                      中当たり　GPAが  5×(賭けGPA) だけ戻ってきます。\n");
    printf("                      小当たり　GPAが  3×(賭けGPA) だけ戻ってきます。\n");
    printf("                      　当たり　GPAが  1×(賭けGPA) だけ戻ってきます。\n");
    printf("                      　ハズレ　GPAは上がらないよ。ゴメンね！\n");
    printf("\n");
    printf("                      　                       ※バグったら　Ctrl + C を押してね\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("\n");
    
    while(1){ // 自分のGPAを入力
        printf("                                                  あなたのGPAを教えてね ： ");
        scanf("%lf",&input);
        gpa=(int)(input*100);
        gpaFirst=gpa;
        
        if(gpa<0 || gpa>400){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("                                    嘘はダメ！\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }else if(gpa==0){
            printf("\n");
            printf("        -----------------------------------------------------------------------------\n");
            printf("\n");
            printf("                             君は参加権すらないよ！来年はいい成績とってね！\n");
            printf("\n");
            printf("                                                                     〜fin〜\n");
            printf("        -----------------------------------------------------------------------------\n");
            printf("\n");
            sleep(2);
            printf("      と思ったけど...\n");
            sleep(2);
            printf("           かわいそうだからGPAを0.5プレゼント！\n");
            printf("\n");
            gpa+=50;
            break;
            
        }else{
            break;
        }
    }
    
    do{ //カジノ部分
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("      GPA,いくら賭ける？(現在のGPA：%.2f)：　",(double)(gpa/100.0));
        scanf("%lf",&gpaInput_double);
        gpaInput_int=(int)(gpaInput_double*100);
        if(gpa-gpaInput_int < 0){
            printf("\n");
            printf("\n");
            printf("                                    君にそんなGPAは残ってないよ！\n");
            printf("\n");
            printf("\n");
            continue;
        }else if(gpaInput_int == 0){
            printf("\n");
            printf("\n");
            printf("                                          賭けGPAがないよ！\n");
            printf("\n");
            printf("\n");
        }
        
        gpa -= gpaInput_int;
        
        printf("\n");
        printf("      オッケー！それではカジノスタート！\n");
        printf("\n");
        printf("                               〜 ルーレットを回す... 〜\n");
        printf("\n");
        sleep(2);
        
        srand((unsigned int)time(NULL));
        judge = rand()%100+1;
        
        if(judge == 1 || judge == 77){
            printf("      おめでとう！大当たりだ！\n");
            gpa+=gpaInput_int*10;
            printf("            今のGPA ：　%.2f\n",(double)(gpa/100.0));
            printf("\n");
        }else if(judge % 25 == 0){
            printf("      やった！中当たりだ！\n");
            gpa+=gpaInput_int*5;
            printf("            今のGPA ：　%.2f\n",(double)(gpa/100.0));
            printf("\n");
        }else if(judge % 6 == 0){
            printf("      よし！小当たりだ！\n");
            gpa+=gpaInput_int*3;
            printf("            今のGPA ：　%.2f\n",(double)(gpa/100.0));
            printf("\n");
        }else if(judge % 4 == 0){
            printf("      堅実に！当たりだ！\n");
            gpa+=gpaInput_int*1;
            printf("            今のGPA ：　%.2f\n",(double)(gpa/100.0));
            printf("\n");
        }else{
            printf("      くそっ！ハズレだ！\n");
            
            if(gpa<=0){
                break;
            }
            
            printf("            今のGPA ：　%.2f\n",(double)(gpa/100.0));
            printf("\n");
        }
        
        printf("                  もう１回やりますか？\n");
        printf("                        ⇨ '    1    ' - もう一度 \n");
        printf("                        ⇨ '1以外の数字' - もうやめる）\n");
        printf("                                               数字を選んでね：");
        scanf("%d",&n);
        
    }while(n==1);
    
    
    if(gpa>=400){ //結果表示
        printf("\n");
        printf("        あなたのGPAは4.00です。(上限突破した分切り捨て)\n");
        printf("             -----------------------------------------------------------------\n");
        printf("\n");
        printf("                     YOU WIN !!\n");
        printf("\n");
        printf("                     やるやん！来年俺にリベンジさせて。では、どうぞ（単位）\n");
        printf("\n");
        printf("             -----------------------------------------------------------------\n");
        printf("\n");
    }else if(gpa<=0){
        printf("\n");
        printf("       あなたのGPAは0.00になりました。\n");
        printf("             -----------------------------------------------------------------------------\n");
        printf("\n");
        printf("                  YOU LOSE !!\n");
        printf("\n");
        printf("                  俺の勝ち！なんで留年になったか来年までに考えてきてください。\n");
        printf("                  そしたら何かが見えてくるはずです。ほな、いただきます。（来年度の学費）\n");
        printf("\n");
        printf("             -----------------------------------------------------------------------------\n");
        printf("\n");
    }else{
        printf("\n");
        printf("       あなたの最終的なGPAは%.2fでした。\n",(double)(gpa/100.0));
        if(gpa<gpaFirst){
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
            printf("                                ギャンブルはやめて真面目に授業に出ましょう。\n");
            printf("\n");
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
        }else if (gpa==gpaFirst){
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
            printf("                            GPA変わらず。君のGPAは運命で決まっていたんでしょう（適当）\n");
            printf("\n");
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
        }else{
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
            printf("                おめでとう！でも、GPA4.00を目指してみたくない？再チャレンジ待ってます。\n");
            printf("\n");
            printf("             -----------------------------------------------------------------------------\n");
            printf("\n");
        }
    }
    return 0;
}
