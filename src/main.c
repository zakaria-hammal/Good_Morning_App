#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <libnotify/notify.h>


typedef struct quote quote;
struct quote
{
    char teller[100];
    char wisdom[1000];
};

int main(int argc, char *argv[])
{
    quote Quotes[] = {
        {"Henry Ford", "When everything seems to be going against you, remember that the airplane takes off against the wind, not with it"},
        {"Winston Churchill", "Success is not final, failure is not fatal: it is the courage to continue that counts"},
        {"Wayne Gretzky", "You miss 100% of the shots you don’t take"},
        {"C.S. Lewis", "Hardships often prepare ordinary people for an extraordinary destiny"},
        {"Henry Ford", "Whether you think you can or think you can’t, you’re right"},
        {"Peter Drucker", "The best way to predict the future is to create it"},
        {"Ralph Waldo Emerson", "What lies behind us and what lies before us are tiny matters compared to what lies within us"},
        {"Nelson Mandela", "It always seems impossible until it’s done"},
        {"Steve Jobs", "Your time is limited, so don’t waste it living someone else’s life"},
        {"Eleanor Roosevelt", "The future belongs to those who believe in the beauty of their dreams"},
        {"Gloria Steinem", "The art of life is not controlling what happens to us, but using what happens to us"},
        {"Unknown", "One of the happiest moments in life is when you find the courage to let go of what you cannot change."},
        {"Dr. Seuss", "Don’t cry because it’s over, smile because it happened"},
        {"Unknown", "When you let go, you create space for better things to enter your life"},
        {"Nicole Sobon", "Sometimes the hardest part isn’t letting go but learning to start over"},
        {"Twenty One Pilots", "The sun will rise and we will try again"}
    };

    srand(time(NULL));
    int i = rand() % (sizeof(Quotes) / sizeof(Quotes[0]));

    char *app_user = getenv("GM_APP_USER");
    
    char greeting[1000];

    snprintf(greeting, sizeof(greeting), "Good Morning %s", app_user);
    
    printf("App is starting\n");
    notify_init("Good Morning");
    
    printf("First notification\n");
    NotifyNotification* n;

    n = notify_notification_new(
        greeting,
        "This is the beginning of a new great day",
        "/home/zakaria/Documents/GoodMorning/good_morning.png"
    );

    notify_notification_set_timeout(n, 10000);

    notify_notification_show(n, NULL);
    
    g_object_unref(G_OBJECT(n));

    sleep(12);
    printf("Second notification\n");
    n = notify_notification_new(
        Quotes[i].teller,
        Quotes[i].wisdom,
        "/home/zakaria/Documents/GoodMorning/good_morning.png"
    );

    notify_notification_set_timeout(n, 12000);

    notify_notification_show(n, NULL);
    
    g_object_unref(G_OBJECT(n));

    printf("Closing the app\n");
    
    return EXIT_SUCCESS;
}
