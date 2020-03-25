#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// type- 1 Newly arrived customer, time will denote arrival time
// type- 2 Customer with completed task, time will denotes its total time spent in the bank
// type- 3 Teller with completed time, time will denote its service time
// type- 4 teller with idle time

struct Event
{
    int type;
    float time;
    struct Customer* cust;
    struct Teller* teller;
    struct Event* next;

};

typedef void (*Push) (struct Event* e, struct Event* current);
typedef struct Event* (*Pop) (struct Event* h);

struct Eventq
{
    struct Event* head;
    Push push;
    Pop pop;
};

void push_event(struct Event* e, struct Event* current){
	if (current-> next == NULL){
		current -> next = e;
		return;
	}
	if (current->next->time > e->time){
		e->next = current->next;
		current -> next = e;
	}else{
		push_event(e,current->next);
	}
}

struct Event* pop_event(struct Event* h){
	struct Event* e1 = h->next;
	h->next = e1->next;
	e1->next = NULL;
	return e1;
}

void printEventList(struct Event* e){
	if(e->next != NULL){
		printf("%f\n", e->next->time);
		printEventList(e->next);
	}
}

struct Customer
{
    float arrival_time;
    float wait_time;
    float service_time;
    float total_time;
    struct Customer* next;
};

typedef void (*Push_cust) (struct Customer*  c, struct Customer* tail);
typedef struct Customer* (*Pop_cust) (struct Customer* h);

struct Teller
{
    float total_idle_time;
    float total_service_time;
    struct Teller* next;
};


struct Tellerq
{
	struct Customer* head;
	struct Customer* tail;
	Push_cust push;
	Pop_cust pop;
};

void push_customer(struct Customer* c, struct Customer* tail){
	tail->next = c;
}

struct Customer* pop_customer(struct Customer* h){
	struct Customer* c = h->next;
	h->next = c->next;
	c->next = NULL;
	return c;
}

int main(int argc, char* argv[]){
	float time = 0;

	struct Event* h;
	h = (struct Event*) malloc (sizeof(struct Event));
	h->time=-1;
	h->next =NULL;
	h->cust = NULL;
	h->teller = NULL;
	struct Eventq* event_queue;
	event_queue = (struct Eventq*) malloc (sizeof(struct Eventq));
	event_queue->head = h;
	event_queue->push = push_event;
	event_queue->pop = pop_event;


	int no_customers = atoi(argv[1]);
	int no_tellers = atoi(argv[2]);
	float simulationTime = atof(argv[3]);
	float avgServiceTime = atof(argv[4]);

	for(int i=0;i<no_tellers;i++){
		struct Event* e = (struct Event*) malloc (sizeof(struct Event));
		e->time =0 ;
		e->next = NULL;
		e->type = 3;

		struct Teller* t = (struct Teller*) malloc (sizeof(struct Teller));
		t->total_idle_time =0;
		t->total_service_time=0;
		t->next = NULL;

		e->teller = t;
		e->cust = NULL;
		event_queue->push(e, event_queue->head);
	}

	for(int i=0;i<no_customers;i++){
		float arrTime = simulationTime * ((1.0*rand())/(1.0*RAND_MAX));
		struct Event* e;
		e = (struct Event*) malloc (sizeof(struct Event));
		e->time = arrTime;
		e->type = 1;
		e->next = NULL;

		struct Customer* new_c = (struct Customer*) malloc (sizeof(struct Customer));
		new_c-> arrival_time = arrival_time;
		new_c->wait_time = 0 ;
		new_c->service_time = 0;
		new_c->total_time = arrival_time;
		new_c->next = NULL;

		e->cust = new_c;
		e->teller = NULL;

		event_queue->push(e, event_queue->head);
	}
	
	printEventList(event_queue->head);
	printf("%s\n", "-------------------------------------------------");
	struct Tellerq* teller_queue;
	teller_queue = (struct Tellerq*) malloc (sizeof(struct Tellerq));
	struct Customer* head_cust = (struct Customer*) malloc(sizeof(struct Customer));
	head_cust -> arrival_time = -1;
    head_cust -> wait_time = -1;
    head_cust -> service_time = -1;
    head_cust -> total_time = -1;
    head_cust -> next = NULL;
    teller_queue -> head = head_cust;
    teller_queue -> push = push_customer;
    teller_queue -> pop = pop_customer;
    

	while(no_customers>0 && time<simulationTime){
		struct Event* e = event_queue -> pop(event_queue->head);
		printf("%f    ", e->time);
		if(e->type==1){
			printf("%s\n", "in 1");
			struct Customer* new_c = (struct Customer*) malloc (sizeof(struct Customer));
			new_c-> arrival_time = e -> time;
			new_c->wait_time = 0 ;
    		new_c->service_time = 0;
    		new_c->total_time = e->time;
    		new_c->next = NULL;
    		teller_queue->push(new_c,teller_queue->head);
		}else if(e->type == 2){
			printf("%s", "in 2  removing customer :");
			printf("%f\n", e->time);
		}else{
			if(teller_queue->head->next == NULL){
				printf("%s\n", "going to 4");
				struct Event* t = (struct Event*) malloc (sizeof(struct Event));
				float idle_time = 2* 75 * ((1.0*rand())/(1.0*RAND_MAX));
				t->time = e->time + idle_time ;
				t->next = NULL;
				t->type = 4;
				event_queue->push(t,event_queue->head);
			}else{
				printf("%s\n", "rest");
				struct Customer* c1 = teller_queue->pop(teller_queue->head);
    			c1->wait_time = e->time - c1->arrival_time;
    			c1->service_time = 2*avgServiceTime* ((1.0*rand())/(1.0*(RAND_MAX)));;
    			c1->total_time = c1->wait_time + c1->service_time;
    			
    			struct Event* cust_event = (struct Event*) malloc (sizeof(struct Event));
    			cust_event->time = e->time + c1->service_time;
				cust_event->next = NULL;
				cust_event->type = 2;
				event_queue->push(cust_event,event_queue->head);

				struct Event* tell_event = (struct Event*) malloc (sizeof(struct Event));
    			tell_event->time = cust_event->time ;
				tell_event->next = NULL;
				tell_event->type = 3;
				event_queue->push(tell_event,event_queue->head);
				no_customers--;
			}
		}
		time = e->time;
	}
}


