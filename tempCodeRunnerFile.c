#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hero = H //
typedef struct Hero {
    int attack;
    int exp;
    int level;
    int health;
    int intelligence;
    int mana;
    int agility;
    int defense;
    char *Name;
    char *Class;
} hero;

typedef struct enemy {
    int atc;
    int lvl;
    int hp;
    int intel;
    int magic;
    int speed;
    int df;
    int number;
    char *name;
} en;

void Enemies(en *e, int enemytype);
void Player(hero *h, int playertype);
void NameChange(hero *h, char Response);
void Story1(hero *h, en *e, int playertype);
void Story2(hero *h, en *e, int choice);
void StoryUntrapped(hero *h, en *e, int choice);
void TunnelArc(hero *h, en *e, int choice);
void Check(hero* h, en* e, int choice);
void Continuation(hero* h, en* e, int choice);
void DarkAbyssalForest(hero* h, en* e, int choice);
void Check1(hero* h, en* e, int choice);
void Continuation1(hero* h, en* e, int choice);
void Response1(hero* h, en* e, int choice);
void PlayerLevelingMechanics(hero *h);
void Fighting_Mechanics(hero *h, en *e);
void RandomEnemy(en *e);

void Player(hero *h, int playertype) {
    h->level = 1;
    h->exp = 0;
    switch (playertype) {
        case 1:
            printf("\nYou chose Rogue!\n");
            h->attack = 25; 
            h->health = 20;
            h->intelligence = 25;
            h->mana = 15;
            h->agility = 25;
            h->defense = 15;
            h->Class = (char *)malloc(100 * sizeof(char));
            strcpy(h->Class, "Rogue");
            break;
        case 2:
            printf("\nYou chose Warrior!\n");
            h->attack = 30;
            h->health = 30;
            h->intelligence = 10;
            h->mana = 10;
            h->agility = 20;
            h->defense = 20;
            h->Class = (char *)malloc(100 * sizeof(char));
            strcpy(h->Class, "Warrior");
            break;
        case 3:
            printf("\nYou chose Mage!\n");
            h->attack = 20;
            h->health = 15;
            h->intelligence = 30;
            h->mana = 30;
            h->agility = 15;
            h->defense = 10;
            h->Class = (char *)malloc(100 * sizeof(char));
            strcpy(h->Class, "Mage");
            break;
        
        
        default:
            printf("Invalid playertype. Defaulting to Rogue.\n");
            playertype = 1;
            Player(h, playertype);
            return;
    }

    printf("Do you want to give your character a name? Press Y for yes and N for no: ");
    char c;
    scanf(" %c", &c);
    NameChange(h, c);
}

void NameChange(hero *h, char Response) {
    if (Response == 'Y' || Response == 'y') {
        printf("\nEnter your character's name: ");
        h->Name = (char *)malloc(100 * sizeof(char));
        scanf("%s", h->Name);
        if (h->Name == NULL) {
            strcpy(h->Name, h->Class);
        }
    } else if (Response == 'N' || Response == 'n') {
        h->Name = (char *)malloc(100 * sizeof(char));
        strcpy(h->Name, h->Class);
    } else {
        printf("\nInvalid Response\n");
        printf("Type again: ");
        scanf(" %c", &Response);
        NameChange(h, Response);
    }
}

void Enemies(en *e, int enemytype) {
    srand(time(NULL));
    switch (enemytype) {
        case 1:
            // KOBOLD //
            e->atc = 14;
            e->lvl = 1;
            e->hp = 10;
            e->intel = 15;
            e->magic = 5;
            e->speed = 15;
            e->df = 10;
            e->number = 7;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Kobold");
            break;
        case 2:
            // GOBLIN //
            e->atc = 20;
            e->lvl = 2;
            e->hp = 15;
            e->intel = 10;
            e->magic = 10;
            e->speed = 20;
            e->df = 10;
            e->number = 5;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Goblin");
            break;
        case 3:
            // TROLL //
            e->atc = 30;
            e->lvl = 3;
            e->hp = 25;
            e->intel = 8;
            e->magic = 5;
            e->speed = 10;
            e->df = 20;
            e->number = rand() % 2 + 1;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Troll");
            break;
        case 4:
            // GOLEM //
            e->atc = 50;
            e->lvl = 4;
            e->hp = 35;
            e->intel = 9;
            e->magic = 5;
            e->speed = 3;
            e->df = 35;
            e->number = 1;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Golem");
            break;
        case 5:
        // ENT //
        e->atc = 20;
            e->lvl = 5;
            e->hp = 30;
            e->intel = 30;
            e->magic = 20;
            e->speed = 4;
            e->df = 15;
            e->number = 1;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Ent");
        break;
        case 6:
        // WRAITH //
        e->atc = 20;
            e->lvl =3;
            e->hp = 10;
            e->intel = 15;
            e->magic = 10;
            e->speed = 30;
            e->df = 10;
            e->number = 7;
            e->name = (char *)malloc(100 * sizeof(char));
            strcpy(e->name, "Wraith");
        break;
        

        default:
            RandomEnemy(e);
            break;
    }
}

void RandomEnemy(en *e) {
    srand(time(NULL));
    e->atc = rand() % 20 + 10;
    e->lvl = rand() % 5 + 1;
    e->hp = rand() % 30 + 10;
    e->intel = rand() % 20 + 5;
    e->magic = rand() % 20 + 5;
    e->speed = rand() % 20 + 5;
    e->df = rand() % 20 + 5;
    e->number = rand()%5+1;
    e->name = (char *)malloc(100 * sizeof(char));
    strcpy(e->name, "Random Enemy");
}

void Story1(hero *h, en *e, int playertype) {
    int choice;
    FILE *Image1 = fopen("Forest.txt", "r");
    if (Image1 == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title0txt = (char *)malloc(999999 * sizeof(char));
    if (Title0txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Image1);
        return;
    }

    while (fgets(Title0txt, 999999, Image1)) {
        printf("%s", Title0txt);
    }

    free(Title0txt);
    fclose(Image1);
    printf("You enter a magical forest.\nThe air is thick with the scent of pine and blooming flowers,\n");
    printf("and a gentle mist rolls through the trees, giving the forest an ethereal glow.\n");
    printf("The sunlight filters through the canopy, casting dappled shadows on the moss-covered ground.\n");
    printf("You can hear the distant call of strange creatures and the rustling of leaves as unseen animals move about.\n");
    printf("As you step deeper into the forest, you come to a fork in the path.\n");
    printf("\nDecision Point: \n");
    printf("(1) Take the left path, which is narrow and overgrown with vines.\n"); 
    printf("(2) Take the right path, which is wide and well-trodden.\n");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice. Try again.\n");
        while (getchar() != '\n'); // Clear input buffer
        Story1(h, e, playertype);
    } else {
        Story2(h, e, choice);
    }
}

void Story2(hero *h, en *e, int choice) {
    srand(time(NULL));
    switch (choice) {
        case 1:
            printf("You decide to take the left path.\n");
            printf("The vines tug at your clothes as you push through the dense foliage.\n");
            printf("The air grows cooler, and the light dims as the trees close in around you.\n");
            printf("Suddenly, you hear a rustling sound nearby.\n");
            if (h->agility > 20) {
                printf("Pass: You nimbly avoid a hidden tripwire.\n");
                h->exp += 1;
                StoryUntrapped(h, e, choice);
            } else {
                printf("Fail: You stumble and trigger the trap, causing a net to spring up and ensnare you.\n");
                h->health -= (rand() % 5 + 1);
                if (h->attack > 15) {
                    printf("\nYou have successfully escaped from the trap\n");
                    h->exp += 1;
                    StoryUntrapped(h, e, choice);
                } else {
                    printf("Due to %s struggling, the net breaks. You fall onto the ground with a thud.\n", h->Name);
                    h->health -= 1;
                    StoryUntrapped(h, e, choice);
                }
            }
            break;
        case 2:
            printf("You take the right path.\n");
            printf("The path is smooth and easy to follow, but you feel a sense of unease.\n");
            
            printf("You hear a growl, and suddenly, a group of %d goblins jumps out from the bushes!\n", e->number);
            
    FILE *Goblin = fopen("Goblin.txt", "r");
    if (Goblin == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title7txt = (char *)malloc(1024 * sizeof(char));
    if (Title7txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Goblin);
        return;
    }

    while (fgets(Title7txt, 1024, Goblin)) {
        printf("%s", Title7txt);
    }

    free(Title7txt);
    fclose(Goblin);
            
            Enemies(e, 2);
            Fighting_Mechanics(h, e);
            TunnelArc(h,e, choice);
            break;
    }
}

void StoryUntrapped(hero *h, en *e, int choice) {
    srand(time(NULL));
    printf("\nAfter some time, you come across a small clearing.\n");
    printf("In the center stands an ancient, gnarled tree with a face carved into its trunk.\n");
    FILE *Ent = fopen("Ent.txt", "r");
    if (Ent == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title3txt = (char *)malloc(1024 * sizeof(char));
    if (Title3txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Ent);
        return;
    }

    while (fgets(Title3txt, 1024, Ent)) {
        printf("%s", Title3txt);
    }

    free(Title3txt);
    fclose(Ent);
    printf("The eyes of the face open, revealing a deep, glowing green light.\n");
    printf("The tree speaks:\n");
    printf("\"Answer my riddle, and you may pass. Fail, and you shall be turned to stone.\"\n");
    printf("\"Riddle me this: I speak without a mouth and hear without ears. I have no body, but I come alive with the wind.\"\n");

    if (h->intelligence > 25) {
        char response;
        printf("Would you like to solve the riddle? Press Y for yes and N for no: ");
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            char answer[100];
            printf("\nYou may answer: \n");
            scanf("%s", &answer);
            if (strcmp(answer, "Echo") == 0 || strcmp(answer, "echo") == 0) {
            printf("Correct answer!\n");
            printf("The tree's eyes flash with approval. 'You are wise. You may pass.'\n");
            printf("A hidden door in the trunk swings open, revealing a tunnel leading downward.\n");
            h->exp += (2 * (rand() % 5 + 1));
        }
        } else {
            printf("The correct answer is: Echo\n");
            printf("The tree's eyes flash with approval. 'You are wise. You may pass.'\n");
            printf("A hidden door in the trunk swings open, revealing a tunnel leading downward.\n");
            h->exp += (rand() % 5 + 1);
        }
    } else {
        char answer[100];
        printf("Guess the answer: ");
        scanf("%s", answer);
        if (strcmp(answer, "Echo") == 0 || strcmp(answer, "echo") == 0) {
            printf("Correct answer!\n");
            printf("The tree's eyes flash with approval. 'You are wise. You may pass.'\n");
            printf("A hidden door in the trunk swings open, revealing a tunnel leading downward.\n");
            h->exp += (2 * (rand() % 5 + 1));
        } else {
            printf("Incorrect. Prepare yourself to fight.\n");
            Enemies(e, 5);

            Fighting_Mechanics(h, e);
        }
    }
}


void TunnelArc(hero *h, en *e, int choice){
    srand(time(NULL));
    printf("As you the %s, The Mighty %s enter tunnel.\n You find the tunnel to be  dark and damp.\n", h->Name, h->Class);
    FILE *CaveTunnel = fopen("Runes.txt", "r");
    if (CaveTunnel == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title6txt = (char *)malloc(1024 * sizeof(char));
    if (Title6txt == NULL) {
        perror("Failed to allocate memory");
        fclose(CaveTunnel);
        return;
    }

    while (fgets(Title6txt, 1024, CaveTunnel)) {
        printf("%s", Title6txt);
    }

    free(Title6txt);
    fclose(CaveTunnel);
    
    printf("You light a torch to see your way.\n As you move forward, you notice ancient runes carved into the walls.\n");
    
    
    FILE *Runes=fopen("Runes.txt", "r");
    if(Runes==NULL){
        return;
    }
    char* Title4txt=(char*)malloc(1024*sizeof(char));
    while(fgets(Runes, sizeof(Title4txt), Runes)){
        printf("%s", Title4txt);
    }
    fclose(Runes);
    
    
    if(h->intelligence>20){
        printf("You decipher the runes, gaining valuable information about the path ahead.\n");
        h->exp=h->exp+(h->exp*rand()%5+1);
        printf("Information Gained: Beware the guardian of the flame, only those pure of heart may claim the prize.\n");
    }
    else{
        printf("The runes are too complex to understand.\n");
    }
    printf("You exit the tunnel and find yourself in a vast underground chamber.\n");
    printf("In the center of the chamber, a pedestal holds a glowing orb of light.\n");
    printf("\nHowever, between you and the orb stands a massive stone golem.\n");


    FILE *Golem = fopen("Golem.txt", "r");
    if (Golem == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title5txt = (char *)malloc(1024 * sizeof(char));
    if (Title5txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Golem);
        return;
    }

    while (fgets(Title5txt, 1024, Golem)) {
        printf("%s", Title5txt);
    }

    free(Title5txt);
    fclose(Golem);
 

    Check(h, e, choice);
}

void Check(hero* h, en* e, int choice){
    int decision=0;
    printf("Chose your action:\n (1) Rip and Tear!\n (2) Use Magic to turn it into a cat\n (3) Try to convince it to let you pass: I am not the droid you are looking for \n");
    scanf("%d", decision);
    if((decision==1)||(decision==2)||(decision==3)){
       switch(decision){
        case 1:
        Enemies(e,4);
        Fighting_Mechanics(h,e);
        h->exp=h->exp+30;
        Continuation(h, e, choice);
        break;
        case 2:
        if(h->mana>17){
            Enemies(e,4);
            printf("You Successfully defeated the Mighty %s\n", e->name);
            h->exp=h->exp+30;
            Continuation(h, e, choice);
        }
        else{
            printf("The spell fizzles, and the golem advances.\n");
        Enemies(e,4);
        Fighting_Mechanics(h,e);
        h->exp=h->exp+30;
        Continuation(h, e, choice);
        }
        break;
        case 3:
        if(h->intelligence>15){
            Enemies(e,4);
            printf("The %s is convinced you're not an enemy and leaves you alone\n", e->number);
            h->exp=h->exp+30;
            Continuation(h, e, choice);
        }
        else{
        Enemies(e,4);
        Fighting_Mechanics(h,e);
        h->exp=h->exp+30;
        Continuation(h, e, choice);
        }
        break;
       }
    }
    else{
        printf("\nInvalid Response! Try Again!\n");
        return Check(h,e,choice);
    }
}

void Continuation(hero* h, en* e, int choice){
    printf("\nWith the golem gone, you approach the pedestal.\n");
    
    FILE *ForestHeart = fopen("ForestHeart.txt", "r");
    if (ForestHeart == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title6txt = (char *)malloc(1024 * sizeof(char));
    if (Title6txt == NULL) {
        perror("Failed to allocate memory");
        fclose(ForestHeart);
        return;
    }

    while (fgets(Title6txt, 1024, ForestHeart)) {
        printf("%s", Title6txt);
    }

    free(Title6txt);
    fclose(ForestHeart);



    printf("The orb pulses with a warm, inviting light. As you reach out to touch it, the light envelops you, filling you with a sense of peace and power.\n You have found the Heart of the Forest,\n a powerful artifact that can heal the land and bestow great wisdom.\n");
    h->health=h->health + 15;
    h->mana=h->mana + 20;
    h->intelligence=h->intelligence+25;
    h->exp=h->exp+40;
    printf("\nHowever, as you turn to leave, the chamber begins to shake.\n The walls crack, and a deep, dark voice echoes through the cavern.\n 'You have taken what is mine. \nNow, face the wrath of the forest's true guardian!'\n");
    printf("\nThe chamber collapses, and you fall into a hidden, dark abyss.\n");    
}


void DarkAbyssalForest(hero* h, en* e, int choice){
    //Title Screen
    FILE *Image1 = fopen("Forest.txt", "r");
    if (Image1 == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title0txt = (char *)malloc(1024 * sizeof(char));
    if (Title0txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Image1);
        return;
    }

    while (fgets(Title0txt, 1024, Image1)) {
        printf("%s", Title0txt);
    }

    free(Title0txt);
    fclose(Image1);




    FILE *TITLESCREEN0 = fopen("DarkForest.txt", "r");
    if (TITLESCREEN0 == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title1txt = (char *)malloc(1024 * sizeof(char));
    if (Title1txt == NULL) {
        perror("Failed to allocate memory");
        fclose(TITLESCREEN0);
        return;
    }

    while (fgets(Title1txt, 1024, TITLESCREEN0)) {
        printf("%s", Title1txt);
    }

    free(Title1txt);
    fclose(TITLESCREEN0);
    printf("You wake up in a twisted version of the forest.\n");
    printf("The trees are blackened, and the air is thick with an eerie fog.\n");
    printf("Strange whispers fill the air, and shadows move just beyond your sight.\n");
    printf("You realize you are not alone.\n");
    printf("You spot %d %s heading straight towards you.\n Their eyes glowing an ethereal hue.\n Their open maws ready to tear your flesh from your bones and make you one of them.\n");
 


    FILE *Wraith = fopen("Wraith.txt", "r");
    if (Wraith == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title2txt = (char *)malloc(1024 * sizeof(char));
    if (Title2txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Wraith);
        return;
    }

    while (fgets(Title2txt, 1024, Wraith)) {
        printf("%s", Title2txt);
    }

    free(Title2txt);
    fclose(Wraith);







    printf("Chose your action: \n(1) Fight the wraiths.\n (2) Use a protective spell. (3) Try to sneak past them.\n");
    Check1(h, e, choice);
    printf("\n"); 
}

void Check1(hero* h, en* e, int choice){
    srand(time(NULL));
    int check=0;
    scanf("%d", &check);
    if((check==1)||(check==2)||(check==3)){
        switch (check){
            case 1:
            Enemies(e,6);
            Fighting_Mechanics(h,e);
            break;
            case 2:
            if(((h->intelligence+h->mana)>30)&&((strcmp(h->Name, "Mage")==0)||(strcmp(h->Class, "Mage")==0||((strcmp(h->Name, "Paladin")==0)||(strcmp(h->Class, "Paladin")==0))))){
                printf("You clasp your hands and start chanting an ancient spell, known only to a select few.\n Your hands start glowing an Ethereal Light. For a moment everything around you is as bright as day. The wraiths chasing you burn before your eyes turning into ashes.\n");
                h->exp=h->exp + 25;

                h->mana=h->mana-15;
            }else{
                printf("You try to summon a spell to weaken your enemy but fail at it.\n");
                h->mana=h->mana-10;
                Enemies(e,6);
                Fighting_Mechanics(h,e);
            }
            break;
            case 3:
            if((h->agility)>20){
                printf("Your superior reflexes are no match for the undead.\n You scale a nearby tree and hide in it's leaves.\n As they pass by you, one of them seems to smell you,\n using the opportunity you throw some dirt into their undead eyes and make good of your escape!\n");
                h->exp=h->exp + 15;
            }else{
                printf("You try to run but fall face first into the ground.\n");
                h->health=h->health-rand()%4+1;
                Enemies(e,6);
                Fighting_Mechanics(h,e);
            }

        }
    }else{
        return (h,e,choice);
    }
}

void Continuation1(hero* h, en* e, int choice){
    printf("You come to a clearing where a dark,\n twisted version of the ancient tree stands.\n");
    
    FILE *Ent = fopen("Ent.txt", "r");
    if (Ent == NULL) {
        perror("Failed to open file");
        return;
    }

    char *Title3txt = (char *)malloc(1024 * sizeof(char));
    if (Title3txt == NULL) {
        perror("Failed to allocate memory");
        fclose(Ent);
        return;
    }

    while (fgets(Title3txt, 1024, Ent)) {
        printf("%s", Title3txt);
    }

    free(Title3txt);
    fclose(Ent);

    printf("The face on the tree is now cruel and malevolent.\n");
    printf("Yet seeing the Forest heart, the ancient let's you pass with a grim face.\n");
    printf("You have a choice, will you help the ancient?\n");
    Response1(h,e,choice);
    
    printf("\n");
}    

void Response1(hero* h, en* e, int choice){
    char Answer;
    scanf("%c", &Answer);
    if((Answer=='Y')||(Answer=='y')){
        printf("You use the artifact, thinking about healing the Tree Ancient.\n");
        if(((h->intelligence+h->mana)>30)&&((strcmp(h->Name, "Mage")==0)||(strcmp(h->Class, "Mage")==0||((strcmp(h->Name, "Paladin")==0)||(strcmp(h->Class, "Paladin")==0))))){
            printf("Due to connection with your divine, you are granted a blessing.\n Amplifying your abilities momentarily multiple folds.\n The forest, the cave, everything is touched by a bright golden light and it fades as quickly as it appeared.\n The forest restored to it's pristine condition.\n");
            printf("\nMonumental achievement!\n");
            h->exp=h->exp+50; 
            printf("The Ancient Tree smiles and hands you a golden apple, permanently boosting your speed, health and mana\n");
            h->mana=h->mana+15;
            h->health=h->health+15;
            h->agility=h->agility+15;
        }
        else{
            printf("Momentarily, the tree glows brightly before gaining it's original shade.\n");
            printf("However it looks saddened by the state of the forest\n");
            printf("It speaks: 'This place is my home, a place with such corrupted is unfit for any and unlike most creatures, we Ents can't move about.\n This is the end for me, child. Fret not, for it isn't you fault. I am glad atleast someone worthy got the artifact.\n Thank you for making the last moments of this old one bearable.'\n");
            printf("The Ancient smiles as it hands you a golden apple from it's branches.\n");
            h->mana=h->mana+15;
            h->health=h->health+15;
            h->agility=h->agility+15;
            printf("Consuming it has permanently boosted your stats\n");
            printf("The old tree withers away before you.\n You find a tiny seed in the apple it gave you in it's last moments.\n You decide to hold on to it.\n");
            
            FILE* EntSeed1=fopen("Seed_Img.txt", "w");
            if(EntSeed1==NULL){
                perror("Failed to open file");
                return;
            }
            char* art1=(char*)malloc(1024*sizeof(char));
            while(fgets(art1, 999999, EntSeed1)){
                printf("%s", art1);
            }
            fclose(EntSeed1);
            
            FILE* EntSeed=fopen("Seed.txt", "w");

            if(EntSeed==NULL){
                return;
            }
            fclose(EntSeed);
        }
        printf("You decide to leave the tree alone and head to a nearby village to rest and get ready for your next adventure.\n");

    }else if((Answer=='N')||(Answer=='n')){
        printf("You decide to leave the tree alone and head to a nearby village to rest and get ready for your next adventure.\n");
    }else{
        printf("\nInvalid Response! Try Again!\n");
        return Response (h, e, choice);
    }


}











void Fighting_Mechanics(hero *h, en *e) {
    srand(time(NULL));

    for (int i = 0; i < e->number; i++) {
        int enemy_hp = e->hp;
        while (h->health > 0 && enemy_hp > 0) {
            int choice;
            printf("Choose your action:\n (1) Attack\n (2) Defend\n");
            if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                printf("Invalid choice. Please try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            
            if (choice == 1) {
                enemy_hp -= (h->attack / (rand() % 5 + 1));
                if (enemy_hp > 0) {
                    int EnemyAttackProbability = rand() % 2 + 1;
                    if (EnemyAttackProbability == 1) {
                        h->health -= (e->atc / (rand() % 5 + 1));
                    } else {
                        enemy_hp += (e->df / (rand() % 5 + 1));
                    }
                }
            } else if (choice == 2) {
                h->health += (h->defense / (rand() % 5 + 1));
            }
            
            printf("Player health: %d\n", h->health);
            printf("Enemy %d health: %d\n", i + 1, enemy_hp);
        }
        
        if (enemy_hp <= 0) {
            printf("You have defeated %s %d!\n", e->name, i + 1);
            int individual_exp = rand() % 5 + 1;
            h->exp += individual_exp;
            printf("You gained %d experience points.\n", individual_exp);
        } else if (h->health <= 0) {
            printf("You have been defeated by %s %d.\n", e->name, i + 1);
            return;
        }
    }

    PlayerLevelingMechanics(h);
}

void PlayerLevelingMechanics(hero *h) {
    int random = 10 * (rand() % 9 + 1);
    if (h->exp > random) {
        int temp = h->level;
        h->level += 1;
        if (h->level > temp) {
            printf("\nLevel up! Experience points have increased your level.\n");
            h->attack += 5;
            h->health += 5;
            h->intelligence += 3;
            h->mana += 3;
            h->agility += 3;
            h->defense += 3;
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed

    hero h = {0};  // Initialize hero
    en e = {0};    // Initialize enemy

    FILE *file0=fopen("welcome.txt", "r");
    if(file0==NULL){
        return;
    }
    
    char* art=(char*)malloc(1024*sizeof(char));
    while (fgets(art, sizeof(art), file0)) {
        printf("%s", art);
    }
    fclose(file0);

    int playertype;

    printf("\n \n \n Choose your playertype:\n (1) Rogue\n (2) Warrior\n (3) Mage\n");
    if (scanf("%d", &playertype) != 1 || (playertype < 1 || playertype > 3)) {
        printf("Invalid playertype. Defaulting to Rogue.\n");
        playertype = 1;
    }

    Player(&h, playertype);
    Enemies(&e, 1); // Default enemy for starting the game
    Story1(&h, &e, playertype);

    // Free allocated memory
    free(h.Name);
    free(h.Class);
    free(e.name);

    return 0;
}





