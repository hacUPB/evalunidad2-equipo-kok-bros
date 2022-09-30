#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = 0;
    eventList->last = 0;
    
    return eventList;
}


Event *SearchEvent(EventList *this, char *name)
{
    Event *actualEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (actualEvent != NULL)
        {
            if (strcmp(name, actualEvent->eventName)==0)
            return actualEvent;
            actualEvent = actualEvent->next;
        }
    }
    actualEvent = NULL;
    return actualEvent;
}

void AddEvent(EventList *this, Event *event)
{
    Event *actualEvent = this->head;
    while (actualEvent != NULL)
    {
        if(strcmp(event->eventName, actualEvent->eventName) == 0)
        return;

        actualEvent = actualEvent->next;
    }
    
   if(this->isEmpty == 0)
   {
        this->last->next = event;
        this->last=event;
   }
   else
   {
       this->head = event;
       this->last = event;
       this->isEmpty = 0;    
   }
}

void RemoveEvent(EventList *this, char *name)
{
    if (this->isEmpty == 0)
    {
       Event *actualEvent = this->head->next;  
       Event *lastEvent = this->head;
       if(strcmp(name, lastEvent->eventName)==0)
       {
            if(lastEvent->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(lastEvent);
            }
            else
            {
                this->head=actualEvent;
                DestroyEvent(lastEvent);
            }
       }
       while (actualEvent != NULL)
       {
            if(strcmp(name, actualEvent->eventName)==0)
            {
                lastEvent->next = actualEvent->next;
                if (this->last->next == NULL)
                {
                    this->last = lastEvent;
                    DestroyEvent(actualEvent);
                }
            }
            lastEvent = actualEvent;
            actualEvent = actualEvent->next;
       }
    }
}

void ListEvents(EventList *this)
{
    if (this->isEmpty == 0)
    {
        Event *actualEvent = this->head;


        while (actualEvent != NULL)
        {
            printf("%s\n", actualEvent->eventName);
            actualEvent = actualEvent->next;
        }       
    }
    else
    {
        printf("empty\n");
    }

}

void DestroyEventList(EventList *this)
{
    free(this);
}