# Makefile robuste qui préserve l'arborescence dans bin/
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -g -I. -IUtils -IUI -IShapes -IUser -IGI -MMD -MP

OBJDIR := bin
TARGET := $(OBJDIR)/projet

# récupère tous les .c sous le répertoire courant, sans le préfixe "./", exclut bin/
SRC := $(shell find . -name '*.c' -not -path './$(OBJDIR)/*' -printf '%P\n')

# transforme foo/bar.c -> bin/foo/bar.o
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

# règle par défaut
.PHONY: all
all: $(TARGET)

# linkage
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@ -lm
	@printf "=> Exécutable : %s\n" "$@"

# règle générique compilation : bin/dir/file.o depuis dir/file.c
# crée le dossier d'objet si besoin
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# inclure les fichiers .d (dépendances d'en-têtes) si présents
-include $(OBJS:.o=.d)

# exécuter le binaire
.PHONY: run
run: $(TARGET)
	@./$(TARGET)

# nettoyage complet
.PHONY: clean
clean:
	@rm -rf $(OBJDIR)
	@printf "=> bin/ supprimé\n"

# debug : affiche les variables utiles (combien de sources/objets)
.PHONY: debug
debug:
	@echo "SRC (fichiers .c trouvés) :"
	@printf "  %s\n" $(SRC)
	@echo ""
	@echo "OBJS (fichiers .o prévus) :"
	@printf "  %s\n" $(OBJS)
	@echo ""
	@echo "Nombre de .c : $$(echo '$(SRC)' | wc -w)"
	@echo "Nombre de .o : $$(echo '$(OBJS)' | wc -w)"

# éviter collisions de noms de cibles
.PHONY: all clean run debug
