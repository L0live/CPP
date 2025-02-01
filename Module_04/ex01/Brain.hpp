#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        std::string ideas[100];

        Brain();
        Brain(const Brain &src);
        ~Brain();

        Brain &operator=(const Brain &src);

        void setIdea(std::string idea, int index);
        std::string getIdea(int index) const;

    private:
        void copyIdeas(const Brain &src);

};

#endif