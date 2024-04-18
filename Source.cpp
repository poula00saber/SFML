#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Font Satoshi_Black, Satoshi_BlackItalic, Satoshi_Bold, Satoshi_BoldItalic, Satoshi_Italic, Satoshi_Light, Satoshi_LightItalic, Satoshi_Medium, Satoshi_MediumItalic, Satoshi_Regular, RobotoCondensed_Bold, good_Times, CinzelDecorative_Bold, CinzelDecorative_Black;
Texture headerTexture, closeTexture, mininmizeTexture, optionsTexture, backgroundTexture, bigButtonTexture, smallButtonTexture, darkBackgroundTexture, darkBackgroundLargeTexture, darkBackgroundSmallTexture, enterValuesBackgroundTexture;
RenderWindow window(VideoMode(1920,1080) ,"Sign in", Style::Default);


struct Header {
    Sprite background,closeBtn, minimizeBtn,optionBtn;
    Text Hello,user, metro;
};
struct button {
    Text btnText;
    Sprite btnSprite;
};
struct balancePanel {
    Sprite panel;
    Text balanceText, amountText;

};
struct signUpBox {
    Sprite background;
    Sprite valueField1;
    Sprite valueField2;
    Sprite valueField3;
    Sprite valueField4;
    Sprite valueField5;
    Sprite button1;
    Text buttonText1;
    Text value1;
    Text value2;
    Text value3;
    Text value4;
    Text value5;
    Text heading1;
    Sprite button2;
    Text signIn;

};

struct signInBox {
    Sprite background;
    Sprite valueField1;
    Sprite valueField2;
    Sprite button1;
    Text buttonText1;
    Text value1;
    Text value2;
    Text heading1;
    Sprite button2;
    Text signUp;

};

struct bigDarkBox {
    Sprite background;
    Sprite valueField1;
    Sprite valueField2;
    Text amountText;
    Text Totxt;             

};

void TexturesAndFonts();
void drawHeader(Header header);
void setHeader(Header& header);        
void drawSignIn(signInBox box);      
void setSingIn(signInBox& box);        // by reference to implement in the main function
void drawSignUp(signUpBox box);
void setSingUp(signUpBox& box);
void btnInitializer(button[], int arrSize);
void drawButton(button button);
void drawButton(button button[], int num);
void setButton(button& button);
void setBalancePanel(balancePanel& balancePanel);
void drawBalancePanel(balancePanel balancePanel);

int main()
{
    TexturesAndFonts();
    Header header;

    balancePanel panel;
    setBalancePanel(panel);

    button addBalance;
    setButton(addBalance);

    button button1[4];
    btnInitializer(button1,4);
    setHeader(header);
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    Sprite background;
    background.setTexture(backgroundTexture);

    button button;
    setButton(button);

    while (window.isOpen() ){
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        drawHeader(header);
        drawBalancePanel(panel);
        drawButton(button1,4);
        drawButton(addBalance);
        window.display();
   }
    return 0;
}



void TexturesAndFonts() {
    Satoshi_Black.loadFromFile("Fonts/Satoshi_Black.otf");
    Satoshi_BlackItalic.loadFromFile("Fonts/Satoshi_BlackItalic.otf");
    Satoshi_Bold.loadFromFile("Fonts/Satoshi_Bold.otf");
    Satoshi_BoldItalic.loadFromFile("Fonts/Satoshi_BoldItalic.otf");
    Satoshi_Italic.loadFromFile("Fonts/Satoshi_Italic.otf");
    Satoshi_Light.loadFromFile("Fonts/Satoshi_Light.otf");
    Satoshi_LightItalic.loadFromFile("Fonts/Satoshi_LightItalic.otf");
    Satoshi_Medium.loadFromFile("Fonts/Satoshi_Medium.otf");
    Satoshi_MediumItalic.loadFromFile("Fonts/Satoshi_MediumItalic.otf");
    Satoshi_Regular.loadFromFile("Fonts/Satoshi_Regular.otf");
    RobotoCondensed_Bold.loadFromFile("Fonts/RobotoCondensed_Bold.ttf");
    good_Times.loadFromFile("Fonts/good_Times.otf");
    CinzelDecorative_Bold.loadFromFile("Fonts/CinzelDecorative_Bold.otf");
    CinzelDecorative_Black.loadFromFile("Fonts/CinzelDecorative_Black.otf");

    headerTexture.loadFromFile("Textures/headerTexture.jpg");
    darkBackgroundLargeTexture.loadFromFile("Textures/backcolor.png");
    smallButtonTexture.loadFromFile("Textures/smallButtonTexture.png");
    enterValuesBackgroundTexture.loadFromFile("Textures/enterValuesBackgroundTexture.png");
    closeTexture.loadFromFile("Textures/close2.png");
    mininmizeTexture.loadFromFile("Textures/minimize6.png");

}
void drawHeader(Header header) {
    window.draw(header.background);
    window.draw(header.user);
    window.draw(header.metro);
    window.draw(header.closeBtn);
    window.draw(header.minimizeBtn);
    window.draw(header.Hello);


}
void setHeader(Header& header) {
    header.background.setTexture(headerTexture);  
    header.background.setPosition(0,-70);
    header.background.setScale(1.5,.3);
    header.user.setFont(Satoshi_Black);
    header.user.setString("User");
    header.user.setCharacterSize(60);
    header.user.setPosition(100, 70);
    header.metro.setFont(Satoshi_Bold);
    header.metro.setString("MetroMate");
    header.metro.setCharacterSize(70);
    header.metro.setPosition(1920 /2 -200, 25);
    header.closeBtn.setTexture(closeTexture);
    header.closeBtn.setScale(.1, .1);
    header.closeBtn.setPosition(1800, 40);

    header.minimizeBtn.setTexture(mininmizeTexture);
    header.minimizeBtn.setScale(1, 1);
    header.minimizeBtn.setPosition(1720, 40);
    header.Hello.setFont(CinzelDecorative_Bold);
    header.Hello.setCharacterSize(60);
    header.Hello.setPosition(100, 10);
    header.Hello.setString("Hello, ");

}
void drawSignIn(signInBox box) {
    window.draw(box.background);
    window.draw(box.valueField1);
    window.draw(box.valueField2);
    window.draw(box.button1);
    window.draw(box.buttonText1);
    window.draw(box.value1);
    window.draw(box.value2);
    window.draw(box.heading1);
    window.draw(box.button2);
    window.draw(box.signUp);


}
void drawSignUp(signUpBox box) {
    window.draw(box.background);
    window.draw(box.valueField1);
    window.draw(box.valueField2);
    window.draw(box.valueField3);
    window.draw(box.valueField4);
    window.draw(box.valueField5);
    window.draw(box.button1);
    window.draw(box.buttonText1);
    window.draw(box.value1);
    window.draw(box.value2);
    window.draw(box.value3);
    window.draw(box.value4);
    window.draw(box.value5);
    window.draw(box.heading1);
    window.draw(box.button2);
    window.draw(box.signIn);


}

void drawButton(button button) {
    window.draw(button.btnSprite);
    window.draw(button.btnText);
}
void drawButton(button button[], int num) {
    for (int i = 0; i < num; i++) {
        window.draw(button[i].btnSprite);
        window.draw(button[i].btnText);
    }
    
 }
void drawBalancePanel(balancePanel balancePanel) {
    window.draw(balancePanel.panel);
    window.draw(balancePanel.amountText);
    window.draw(balancePanel.balanceText);
}



void setSingIn(signInBox& box) {

    box.background.setTexture(darkBackgroundLargeTexture);
    box.background.setScale( 2.5,1.2);
    box.background.setPosition(1920/2 , 1080/2 + 25);
    box.background.setOrigin(box.background.getLocalBounds().width/2, box.background.getLocalBounds().height / 2); // to change the origin point to the center instead of the top left.
    box.button1.setTexture(smallButtonTexture); 
    box.button1.setOrigin(box.button1.getLocalBounds().width / 2, box.button1.getLocalBounds().height / 2);
    box.button1.setPosition(1920 / 2 + 400, 1080 / 2 + 200);
    box.button1.setScale(.11, .11);
    box.buttonText1.setFont(Satoshi_Medium);
    box.buttonText1.setString("Sign In");
    box.buttonText1.setCharacterSize(30);
    box.buttonText1.setOrigin(box.buttonText1.getLocalBounds().width / 2, box.buttonText1.getLocalBounds().height / 2);
    box.buttonText1.setPosition(box.button1.getPosition().x -5 ,box.button1.getPosition().y - 5 );
    box.value1.setFont(Satoshi_Regular);
    box.value1.setCharacterSize(28);
    box.value1.setString("Email: ");
    box.value1.setOrigin(box.value1.getLocalBounds().width / 2, box.value1.getLocalBounds().height / 2);
    box.value1.setPosition(1920 / 2 + 50, 1080 / 2 -100);
    box.value2.setFont(Satoshi_Regular);
    box.value2.setCharacterSize(28);
    box.value2.setString("Password: ");
    box.value2.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value2.setPosition(1920 / 2 + 50, 1080 / 2);
    box.valueField1.setTexture(enterValuesBackgroundTexture);
    box.valueField1.setScale(1.7, .9);
    box.valueField1.setOrigin(box.valueField1.getLocalBounds().width / 2, box.valueField1.getLocalBounds().height / 2);
    box.valueField1.setPosition(box.value1.getPosition().x + 340, box.value1.getPosition().y + 20);
    box.valueField2.setTexture(enterValuesBackgroundTexture);
    box.valueField2.setScale(1.7, .9);
    box.valueField2.setOrigin(box.valueField2.getLocalBounds().width / 2, box.valueField2.getLocalBounds().height / 2);
    box.valueField2.setPosition(box.value2.getPosition().x + 340, box.value2.getPosition().y + 20);
    box.heading1.setFont(Satoshi_BoldItalic);
    box.heading1.setCharacterSize(32);
    box.heading1.setString("Dont have an account? ");
    box.heading1.setOrigin(box.heading1.getLocalBounds().width / 2, box.heading1.getLocalBounds().height / 2);
    box.heading1.setPosition(box.value1.getPosition().x -440, box.value1.getPosition().y );
    box.button2.setTexture(smallButtonTexture);
    box.button2.setOrigin(box.button2.getLocalBounds().width / 2, box.button2.getLocalBounds().height / 2);
    box.button2.setPosition(box.value2.getPosition().x - 440, box.value2.getPosition().y);
    box.button2.setScale(.11, .11);
    box.signUp.setFont(Satoshi_Medium);
    box.signUp.setString("Sign Up");
    box.signUp.setCharacterSize(30);
    box.signUp.setOrigin(box.signUp.getLocalBounds().width / 2, box.signUp.getLocalBounds().height / 2);
    box.signUp.setPosition(box.button2.getPosition().x - 5, box.button2.getPosition().y - 5);


}

void setSingUp(signUpBox& box) {

    box.background.setTexture(darkBackgroundLargeTexture);
    box.background.setScale(1.45, 1);
    box.background.setPosition(1920 / 2, 1080 / 2 + 25);
    box.background.setOrigin(box.background.getLocalBounds().width / 2, box.background.getLocalBounds().height / 2);
    box.value1.setFont(Satoshi_Regular);
    box.value1.setCharacterSize(28);
    box.value1.setString("      Username: ");
    box.value1.setOrigin(box.value1.getLocalBounds().width / 2, box.value1.getLocalBounds().height / 2);
    box.value1.setPosition(1920 / 2 + 50, 1080 / 2 -300);
    box.value2.setFont(Satoshi_Regular);
    box.value2.setCharacterSize(28);
    box.value2.setString("Email: ");
    box.value2.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value2.setPosition(1920 / 2 + 50, 1080 / 2 -200);
    box.value3.setFont(Satoshi_Regular);
    box.value3.setCharacterSize(28);
    box.value3.setString("Password: ");
    box.value3.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value3.setPosition(1920 / 2 + 50, 1080 / 2 - 100);
    box.value4.setFont(Satoshi_Regular);
    box.value4.setCharacterSize(28);
    box.value4.setString("Confirm Password: ");
    box.value4.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value4.setPosition(1920 / 2 + 50, 1080 / 2 );
    box.value5.setFont(Satoshi_Regular);
    box.value5.setCharacterSize(28);
    box.value5.setString("Balance: ");
    box.value5.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value5.setPosition(1920 / 2 + 50, 1080 / 2 + 100);
    box.valueField1.setTexture(enterValuesBackgroundTexture);
    box.valueField1.setScale(1.9, .9);
    box.valueField1.setOrigin(box.valueField1.getLocalBounds().width / 2, box.valueField1.getLocalBounds().height / 2);
    box.valueField1.setPosition(box.value1.getPosition().x + 450, box.value1.getPosition().y + 20);
    box.valueField2.setTexture(enterValuesBackgroundTexture);
    box.valueField2.setScale(1.9, .9);
    box.valueField2.setOrigin(box.valueField2.getLocalBounds().width / 2, box.valueField2.getLocalBounds().height / 2);
    box.valueField2.setPosition(box.value2.getPosition().x + 450, box.value2.getPosition().y + 20);
    box.valueField3.setTexture(enterValuesBackgroundTexture);
    box.valueField3.setScale(1.9, .9);
    box.valueField3.setOrigin(box.valueField3.getLocalBounds().width / 2, box.valueField3.getLocalBounds().height / 2);
    box.valueField3.setPosition(box.value3.getPosition().x + 450, box.value3.getPosition().y + 20);
    box.valueField4.setTexture(enterValuesBackgroundTexture);
    box.valueField4.setScale(1.9, .9);
    box.valueField4.setOrigin(box.valueField4.getLocalBounds().width / 2, box.valueField4.getLocalBounds().height / 2);
    box.valueField4.setPosition(box.value4.getPosition().x + 450, box.value4.getPosition().y + 20);
    box.valueField5.setTexture(enterValuesBackgroundTexture);
    box.valueField5.setScale(1.9, .9);
    box.valueField5.setOrigin(box.valueField5.getLocalBounds().width / 2, box.valueField5.getLocalBounds().height / 2);
    box.valueField5.setPosition(box.value5.getPosition().x + 450, box.value5.getPosition().y + 20);
    box.button1.setTexture(smallButtonTexture);
    box.button1.setOrigin(box.button1.getLocalBounds().width / 2, box.button1.getLocalBounds().height / 2);
    box.button1.setPosition(1920 / 2 + 500, 1080 / 2 + 250);
    box.button1.setScale(.11, .11);
    box.buttonText1.setFont(Satoshi_Medium);
    box.buttonText1.setString("Register");
    box.buttonText1.setCharacterSize(30);
    box.buttonText1.setOrigin(box.buttonText1.getLocalBounds().width / 2, box.buttonText1.getLocalBounds().height / 2);
    box.buttonText1.setPosition(box.button1.getPosition().x - 5, box.button1.getPosition().y - 5); box.heading1.setFont(Satoshi_BoldItalic);
    box.heading1.setCharacterSize(32);
    box.heading1.setString("Already have an account? ");
    box.heading1.setOrigin(box.heading1.getLocalBounds().width / 2, box.heading1.getLocalBounds().height / 2);
    box.heading1.setPosition(box.value3.getPosition().x - 500, box.value3.getPosition().y);
    box.button2.setTexture(smallButtonTexture);
    box.button2.setOrigin(box.button2.getLocalBounds().width / 2, box.button2.getLocalBounds().height / 2);
    box.button2.setPosition(box.heading1.getPosition().x , box.heading1.getPosition().y + 100);
    box.button2.setScale(.11, .11);
    box.signIn.setFont(Satoshi_Medium);
    box.signIn.setString("Sign In");
    box.signIn.setCharacterSize(30);
    box.signIn.setOrigin(box.signIn.getLocalBounds().width / 2, box.signIn.getLocalBounds().height / 2);
    box.signIn.setPosition(box.button2.getPosition().x - 5, box.button2.getPosition().y - 5);
}
void btnInitializer(button button[], int arrSize) {
    string btnstring[4] = { "Profile","Subscription", "History", "Brief" };

    for (int i = 0; i < arrSize; i++) {
        button[i].btnSprite.setTexture(smallButtonTexture);
        button[i].btnText.setFont(Satoshi_Black); 
        button[i].btnText.setFillColor(Color::White);
        button[i].btnSprite.setPosition(80, 500 + ((i) * 115));
        button[i].btnSprite.setScale(.136, .11);
        button[i].btnText.setString(btnstring[i]);
    }
        button[0].btnText.setPosition(button[0].btnSprite.getPosition().x +80, button[0].btnSprite.getPosition().y+10);
        button[1].btnText.setPosition(button[1].btnSprite.getPosition().x +80, button[1].btnSprite.getPosition().y+10);
        button[2].btnText.setPosition(button[2].btnSprite.getPosition().x +80, button[2].btnSprite.getPosition().y+10);
        button[3].btnText.setPosition(button[3].btnSprite.getPosition().x +80, button[3].btnSprite.getPosition().y+10);

    
}
void setBalancePanel(balancePanel& balancePanel) {
    string panelText[2] = { "Balance" , "0,0 EG" };
    balancePanel.panel.setTexture(darkBackgroundLargeTexture);
    balancePanel.panel.setPosition( 100 , 200);
    balancePanel.panel.setScale(2.9, .38);

    balancePanel.balanceText.setFont(RobotoCondensed_Bold);
    balancePanel.balanceText.setCharacterSize(70);
    balancePanel.balanceText.setPosition(250, 200);
    balancePanel.balanceText.setString(panelText[0]);
    balancePanel.amountText.setFont(RobotoCondensed_Bold);
    balancePanel.amountText.setCharacterSize(70);
    balancePanel.amountText.setPosition(250,300);
    balancePanel.amountText.setString(panelText[1]);
  
}


void setButton(button& button) {
    string buttonText = "Add balance";
    button.btnSprite.setTexture(smallButtonTexture);
    button.btnSprite.setPosition(1250, 250);
    button.btnSprite.setScale(.2, .2);
    button.btnText.setFont(Satoshi_Bold);
    button.btnText.setCharacterSize(55);
    button.btnText.setPosition(button.btnSprite.getPosition().x + 75, button.btnSprite.getPosition().y + 15);
    button.btnText.setString(buttonText);
}



