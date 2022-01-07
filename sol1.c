#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>

typedef struct {
    int value;
    int suit;
} card_t;

int
is_black(int suit)
{
    /*
	hearts   0  00
	diamonds 1  01
	clubs    2  10
	spades   3  11
    */

    return (suit & 2);
}

void
init_deck(card_t *deck)
{
    int card;
    int s, v;

    /* build the deck */

    card = 0;
    for (s = 0; s < 4; s++) {
	for (v = 0; v < 13; v++) {
	    deck[card].value = v;
	    deck[card].suit = s;
	    card++;
	}
    }
}

void
shuffle_card(card_t *deck, int i, int j)
{
    card_t swapval;

    swapval = deck[i];
    deck[i] = deck[j];
    deck[j] = swapval;
}

void
shuffle_deck(card_t *deck)
{
    int card, rand_card;

    /* init the rand num gen */

    srand( time(NULL) );

    /* walk through each card and exchange it with another random card */

    for (card = 0; card < 52; card++) {
	rand_card = (int) rand() % 52;
	shuffle_card(deck, card, rand_card);
    }
}

void
show_deck(card_t *deck, const char *label)
{
    int card;
    char tmpstr[4]; /* "%c%c \0" */
    char cardval[] = "A23456789XJQK";

    /* iterate through the deck and display each card */

    _settextcolor(15); /* br white */
    _outtext(label);

    for (card = 0; card < 52; card++) {
	if (is_black(deck[card].suit)) {
	    _settextcolor(7); /* white */
	}
	else {
	    _settextcolor(4); /* red */
	}

	sprintf(tmpstr, "%c%c ", cardval[ deck[card].value ], deck[card].suit + 3);
	_outtext(tmpstr);
    }
}

int
main()
{
    card_t deck[52];

    /* initalize values in the deck */

    init_deck(deck);

    /* print out the deck */

    show_deck(deck, "Before shuffing: ");

    /* shuffle the deck */

    shuffle_deck(deck);

    /* print the deck */

    show_deck(deck, "\nAfter shuffling: ");

    return 0;
}
