#include "pch.h"
#include "SalamiDatabase.h"

namespace Salami::Data
{
    std::vector<Models::SalamiVariety> SalamiDatabase::GetAllSalamiVarieties()
    {
        std::vector<Models::SalamiVariety> varieties;
        
        auto italian = CreateItalianSalamis();
        auto spanish = CreateSpanishSalamis();
        auto french = CreateFrenchSalamis();
        auto german = CreateGermanSalamis();
        auto other = CreateOtherSalamis();
        
        varieties.insert(varieties.end(), italian.begin(), italian.end());
        varieties.insert(varieties.end(), spanish.begin(), spanish.end());
        varieties.insert(varieties.end(), french.begin(), french.end());
        varieties.insert(varieties.end(), german.begin(), german.end());
        varieties.insert(varieties.end(), other.begin(), other.end());
        
        return varieties;
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::GetVarietiesByRegion(Models::Region region)
    {
        auto all = GetAllSalamiVarieties();
        std::vector<Models::SalamiVariety> filtered;
        
        for (const auto& variety : all)
        {
            if (variety.region == region)
            {
                filtered.push_back(variety);
            }
        }
        
        return filtered;
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::GetVarietiesBySpiceLevel(Models::SpiceLevel level)
    {
        auto all = GetAllSalamiVarieties();
        std::vector<Models::SalamiVariety> filtered;
        
        for (const auto& variety : all)
        {
            if (variety.spiceLevel == level)
            {
                filtered.push_back(variety);
            }
        }
        
        return filtered;
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::CreateItalianSalamis()
    {
        return {
            {
                L"Genoa Salami",
                L"Traditional Italian salami from Genoa, featuring a distinctive red wine flavor and coarse texture. Made with pork, wine, garlic, and peppercorns.",
                Models::Region::Italy,
                L"Liguria, Italy",
                Models::SpiceLevel::Medium,
                Models::Texture::Coarse,
                Models::CuringTime::Medium,
                {L"Pork", L"Red Wine", L"Garlic", L"Salt"},
                {L"Black Pepper", L"White Pepper", L"Fennel"},
                L"Wine-forward with garlic notes and peppery finish",
                L"Provolone cheese, Chianti wine",
                false,
                L"Genoa salami was traditionally made by Genoese sailors for long sea voyages",
                9
            },
            {
                L"Soppressata",
                L"A pressed salami with chunks of fat, featuring bold spices including hot peppers. Known for its marbled appearance and rich, spicy flavor.",
                Models::Region::Italy,
                L"Southern Italy",
                Models::SpiceLevel::Hot,
                Models::Texture::Coarse,
                Models::CuringTime::Long,
                {L"Pork Shoulder", L"Pork Fat", L"Salt"},
                {L"Red Pepper Flakes", L"Black Pepper", L"Garlic"},
                L"Spicy and bold with visible fat marbling",
                L"Pecorino Romano, Aglianico wine",
                true,
                L"The name 'soppressata' comes from the pressing process during curing",
                10
            },
            {
                L"Milano Salami",
                L"Finely ground, mild-flavored salami with subtle garlic notes. Has a smooth texture and is perfect for those preferring less spice.",
                Models::Region::Italy,
                L"Milano, Italy",
                Models::SpiceLevel::Mild,
                Models::Texture::Fine,
                Models::CuringTime::Medium,
                {L"Pork", L"Beef", L"Salt"},
                {L"Garlic", L"White Pepper", L"White Wine"},
                L"Mild and delicate with subtle garlic sweetness",
                L"Fontina cheese, Pinot Grigio wine",
                false,
                L"Milano salami uses rice in the casing which creates its distinctive white coating",
                8
            },
            {
                L"Calabrese (Nduja)",
                L"Spicy, spreadable salami from Calabria. Made with Calabrian chili peppers, giving it a distinctive red color and fiery kick.",
                Models::Region::Italy,
                L"Calabria, Italy",
                Models::SpiceLevel::VeryHot,
                Models::Texture::Spreadable,
                Models::CuringTime::Short,
                {L"Pork", L"Pork Fat", L"Calabrian Chilies"},
                {L"Hot Peppers", L"Salt", L"Black Pepper"},
                L"Intensely spicy with rich pork fat undertones",
                L"Fresh mozzarella, Primitivo wine",
                true,
                L"Nduja is often spread on warm bread where it melts into a spicy, savory topping",
                9
            },
            {
                L"Finocchiona",
                L"A Tuscan salami flavored with fennel seeds. It has a sweet, aromatic flavor and soft texture.",
                Models::Region::Italy,
                L"Tuscany, Italy",
                Models::SpiceLevel::Mild,
                Models::Texture::Medium,
                Models::CuringTime::Medium,
                {L"Pork", L"Salt", L"Fennel Seeds"},
                {L"Fennel", L"Black Pepper", L"Garlic"},
                L"Sweet and aromatic with prominent fennel flavor",
                L"Pecorino Toscano, Chianti Classico",
                true,
                L"Fennel was used because it was cheaper than black pepper during medieval times",
                8
            },
            {
                L"Cacciatore",
                L"Small, compact salami perfect for snacking. The name means 'hunter' because it was easy to carry on hunts.",
                Models::Region::Italy,
                L"Northern Italy",
                Models::SpiceLevel::Medium,
                Models::Texture::Medium,
                Models::CuringTime::Short,
                {L"Pork", L"Salt"},
                {L"Black Pepper", L"Garlic", L"Wine"},
                L"Balanced and versatile with wine notes",
                L"Aged Asiago, Barbera wine",
                false,
                L"Cacciatore salamis are small enough to fit in a hunter's pocket",
                7
            },
            {
                L"Felino",
                L"From Parma, this delicate salami has a wine-based cure and uses only the finest cuts of pork.",
                Models::Region::Italy,
                L"Parma, Italy",
                Models::SpiceLevel::Mild,
                Models::Texture::Fine,
                Models::CuringTime::Long,
                {L"Pork Loin", L"Salt", L"White Wine"},
                {L"White Pepper", L"Garlic"},
                L"Refined and delicate with wine sweetness",
                L"Parmigiano-Reggiano, Lambrusco",
                true,
                L"Salame Felino is made exclusively in the castle town of Felino",
                9
            }
        };
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::CreateSpanishSalamis()
    {
        return {
            {
                L"Chorizo",
                L"Spanish cured sausage heavily seasoned with smoked paprika (pimentón), giving it a distinctive red color and smoky flavor.",
                Models::Region::Spain,
                L"Spain",
                Models::SpiceLevel::Medium,
                Models::Texture::Coarse,
                Models::CuringTime::Medium,
                {L"Pork", L"Smoked Paprika", L"Salt"},
                {L"Paprika", L"Garlic", L"Oregano"},
                L"Smoky and paprika-forward with garlic notes",
                L"Manchego cheese, Rioja wine",
                false,
                L"The red color comes from paprika, not chili peppers like many assume",
                10
            },
            {
                L"Salchichón",
                L"Similar to Italian salami but with black peppercorns and nutmeg. Finely minced with a delicate, slightly sweet flavor.",
                Models::Region::Spain,
                L"Spain",
                Models::SpiceLevel::Mild,
                Models::Texture::Fine,
                Models::CuringTime::Medium,
                {L"Pork", L"Salt"},
                {L"Black Pepper", L"Nutmeg", L"White Pepper"},
                L"Delicate and slightly sweet with peppery finish",
                L"Mahón cheese, Cava",
                false,
                L"Salchichón is often enjoyed during Spanish breakfast with tomato bread",
                8
            },
            {
                L"Lomo Embuchado",
                L"Cured pork loin, technically not salami but often grouped with cured meats. Lean and tender with paprika coating.",
                Models::Region::Spain,
                L"Extremadura, Spain",
                Models::SpiceLevel::Mild,
                Models::Texture::Fine,
                Models::CuringTime::Long,
                {L"Pork Loin", L"Salt", L"Paprika"},
                {L"Paprika", L"Garlic", L"Oregano"},
                L"Lean, tender, and mildly spiced",
                L"Idiazábal cheese, Tempranillo",
                true,
                L"Lomo is one of the leanest cured meats available",
                7
            },
            {
                L"Fuet",
                L"Thin, dry Catalan sausage with a characteristic white mold coating. Simple and traditional.",
                Models::Region::Spain,
                L"Catalonia, Spain",
                Models::SpiceLevel::Mild,
                Models::Texture::Fine,
                Models::CuringTime::Medium,
                {L"Pork", L"Salt"},
                {L"Black Pepper", L"Garlic"},
                L"Simple, pure pork flavor with mild spicing",
                L"Tetilla cheese, Albariño wine",
                true,
                L"Fuet's white coating is penicillium mold, which is completely safe to eat",
                8
            }
        };
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::CreateFrenchSalamis()
    {
        return {
            {
                L"Saucisson Sec",
                L"French dry-cured sausage often studded with peppercorns, herbs, or even truffles. A staple of French charcuterie.",
                Models::Region::France,
                L"France",
                Models::SpiceLevel::Medium,
                Models::Texture::Medium,
                Models::CuringTime::Long,
                {L"Pork", L"Salt"},
                {L"Black Pepper", L"Herbs de Provence"},
                L"Herbal and rustic with wine notes",
                L"Comté cheese, Beaujolais",
                false,
                L"Saucisson sec is the most popular charcuterie item in France",
                9
            },
            {
                L"Rosette de Lyon",
                L"Large diameter dry sausage from Lyon with a distinctive rose-like appearance when sliced.",
                Models::Region::France,
                L"Lyon, France",
                Models::SpiceLevel::Mild,
                Models::Texture::Medium,
                Models::CuringTime::VeryLong,
                {L"Pork", L"Salt"},
                {L"Black Pepper", L"Garlic", L"Wine"},
                L"Rich and complex with long aging character",
                L"Saint-Nectaire cheese, Côtes du Rhône",
                true,
                L"Rosette takes its name from the rose-like pattern created when sliced",
                8
            },
            {
                L"Saucisson d'Arles",
                L"A sausage from Provence, often eaten fresh but also dried. Flavored with local herbs.",
                Models::Region::France,
                L"Arles, France",
                Models::SpiceLevel::Mild,
                Models::Texture::Coarse,
                Models::CuringTime::Short,
                {L"Pork", L"Beef", L"Salt"},
                {L"Thyme", L"Bay Leaf", L"Black Pepper"},
                L"Herbal and aromatic with Provençal character",
                L"Banon cheese, Rosé wine",
                true,
                L"This sausage was granted AOC status in 2017",
                7
            }
        };
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::CreateGermanSalamis()
    {
        return {
            {
                L"Teewurst",
                L"German spreadable salami with a smooth texture, traditionally enjoyed with tea. Made from pork and bacon with a rich, smoky flavor.",
                Models::Region::Germany,
                L"Germany",
                Models::SpiceLevel::Mild,
                Models::Texture::Spreadable,
                Models::CuringTime::Short,
                {L"Pork", L"Bacon", L"Salt"},
                {L"White Pepper", L"Cardamom", L"Nutmeg"},
                L"Rich, smoky, and spreadable",
                L"Butterkäse, Riesling",
                false,
                L"Teewurst literally means 'tea sausage' and was traditionally eaten at tea time",
                7
            },
            {
                L"Mettwurst",
                L"Soft, spreadable German sausage that can be cured or fresh. Strong garlic flavor.",
                Models::Region::Germany,
                L"Northern Germany",
                Models::SpiceLevel::Medium,
                Models::Texture::Spreadable,
                Models::CuringTime::Short,
                {L"Pork", L"Beef", L"Salt"},
                {L"Garlic", L"Black Pepper", L"Coriander"},
                L"Bold garlic flavor with spreadable texture",
                L"Emmental, German Pilsner",
                false,
                L"Mettwurst is often enjoyed raw on bread for breakfast in Germany",
                8
            },
            {
                L"Landjäger",
                L"Semi-dried sausage pressed into a rectangular shape. Perfect for hiking and outdoor activities.",
                Models::Region::Germany,
                L"Bavaria, Germany",
                Models::SpiceLevel::Medium,
                Models::Texture::Medium,
                Models::CuringTime::Short,
                {L"Pork", L"Beef", L"Salt"},
                {L"Caraway", L"Garlic", L"Black Pepper"},
                L"Tangy and firm with caraway notes",
                L"Limburger cheese, German Lager",
                false,
                L"The rectangular shape makes it easy to pack for mountain climbing",
                7
            }
        };
    }

    std::vector<Models::SalamiVariety> SalamiDatabase::CreateOtherSalamis()
    {
        return {
            {
                L"Hungarian Salami",
                L"Made with Hungarian paprika and white mold coating. One of the finest salamis in the world.",
                Models::Region::Hungary,
                L"Hungary",
                Models::SpiceLevel::Medium,
                Models::Texture::Fine,
                Models::CuringTime::VeryLong,
                {L"Pork", L"Bacon", L"Salt"},
                {L"Hungarian Paprika", L"White Pepper", L"Garlic"},
                L"Complex and refined with paprika warmth",
                L"Aged Gouda, Tokaji wine",
                true,
                L"Hungarian salami won gold at the 1935 Brussels World Fair",
                10
            },
            {
                L"Kielbasa",
                L"Polish smoked sausage, while not technically salami, often included in cured meat selections.",
                Models::Region::Poland,
                L"Poland",
                Models::SpiceLevel::Medium,
                Models::Texture::Coarse,
                Models::CuringTime::Short,
                {L"Pork", L"Beef", L"Salt"},
                {L"Garlic", L"Marjoram", L"Black Pepper"},
                L"Smoky and garlicky with robust flavor",
                L"Oscypek cheese, Polish beer",
                false,
                L"There are over 100 varieties of kielbasa in Poland",
                8
            }
        };
    }

    std::vector<Models::Recipe> SalamiDatabase::GetAllRecipes()
    {
        std::vector<Models::Recipe> recipes;
        
        auto appetizers = CreateAppetizerRecipes();
        auto mains = CreateMainCourseRecipes();
        auto snacks = CreateSnackRecipes();
        
        recipes.insert(recipes.end(), appetizers.begin(), appetizers.end());
        recipes.insert(recipes.end(), mains.begin(), mains.end());
        recipes.insert(recipes.end(), snacks.begin(), snacks.end());
        
        return recipes;
    }

    std::vector<Models::Recipe> SalamiDatabase::GetRecipesByCategory(const std::wstring& category)
    {
        auto all = GetAllRecipes();
        std::vector<Models::Recipe> filtered;
        
        for (const auto& recipe : all)
        {
            if (recipe.category == category)
            {
                filtered.push_back(recipe);
            }
        }
        
        return filtered;
    }

    std::vector<Models::Recipe> SalamiDatabase::CreateAppetizerRecipes()
    {
        return {
            {
                L"Classic Salami & Cheese Board",
                L"An elegant charcuterie board featuring premium salami varieties, artisanal cheeses, and accompaniments",
                L"Appetizer",
                8,
                20,
                0,
                L"Easy",
                {
                    L"200g Genoa salami, thinly sliced",
                    L"150g Soppressata, thinly sliced",
                    L"100g Milano salami, thinly sliced",
                    L"150g aged Parmesan cheese, cut into chunks",
                    L"100g Manchego cheese, sliced",
                    L"100g Brie cheese, wedges",
                    L"Fresh figs, halved",
                    L"Seedless grapes, bunches",
                    L"Marcona almonds",
                    L"Honey for drizzling",
                    L"Crusty baguette slices",
                    L"Cornichons",
                    L"Whole grain mustard",
                    L"Fresh rosemary sprigs for garnish"
                },
                {
                    L"Select a large wooden board or slate platter",
                    L"Arrange cheeses in different areas of the board, varying heights and textures",
                    L"Fold salami slices into quarters or roll them for visual appeal",
                    L"Create salami 'roses' by overlapping thin slices in a circle",
                    L"Place larger items first, then fill gaps with smaller items",
                    L"Add fresh figs and grapes for color and sweetness",
                    L"Scatter almonds throughout the board",
                    L"Place small bowls of honey, cornichons, and mustard on the board",
                    L"Drizzle honey over cheese just before serving",
                    L"Garnish with fresh rosemary sprigs",
                    L"Serve with baguette slices on the side or arranged on board"
                },
                {
                    L"Let salami come to room temperature 30 minutes before serving for best flavor",
                    L"Use odd numbers when arranging items for visual balance",
                    L"Vary colors, textures, and heights for an appealing presentation",
                    L"Provide small cheese knives and picks for easy serving"
                },
                L"Mixed Varieties",
                {L"Chianti", L"Pinot Noir", L"Prosecco"}
            },
            {
                L"Salami-Stuffed Mushrooms",
                L"Savory appetizer featuring button mushrooms stuffed with salami, cheese, and herbs",
                L"Appetizer",
                6,
                15,
                20,
                L"Easy",
                {
                    L"24 large button mushrooms, stems removed",
                    L"150g salami, finely diced",
                    L"100g cream cheese, softened",
                    L"50g Parmesan cheese, grated",
                    L"2 cloves garlic, minced",
                    L"2 tbsp fresh parsley, chopped",
                    L"1 tbsp olive oil",
                    L"Salt and pepper to taste",
                    L"Bread crumbs for topping"
                },
                {
                    L"Preheat oven to 375°F (190°C)",
                    L"Clean mushrooms and remove stems",
                    L"Brush mushroom caps with olive oil",
                    L"In a bowl, mix diced salami, cream cheese, Parmesan, garlic, and parsley",
                    L"Season mixture with salt and pepper",
                    L"Fill each mushroom cap generously with the mixture",
                    L"Top with bread crumbs",
                    L"Place on baking sheet",
                    L"Bake for 20 minutes until golden and bubbly",
                    L"Let cool for 5 minutes before serving"
                },
                {
                    L"Choose mushrooms of similar size for even cooking",
                    L"Don't overfill the mushrooms to prevent spillage",
                    L"Can be prepared ahead and refrigerated until baking"
                },
                L"Milano or Genoa",
                {L"Chardonnay", L"Sauvignon Blanc"}
            },
            {
                L"Salami Pinwheels",
                L"Easy-to-make spiral appetizers with salami, cream cheese, and vegetables",
                L"Appetizer",
                12,
                15,
                0,
                L"Easy",
                {
                    L"4 large flour tortillas",
                    L"200g cream cheese, softened",
                    L"150g salami slices",
                    L"1 cup fresh spinach leaves",
                    L"1 red bell pepper, thinly sliced",
                    L"2 tbsp fresh basil, chopped",
                    L"1 tsp garlic powder",
                    L"Salt and pepper to taste"
                },
                {
                    L"Mix cream cheese with basil, garlic powder, salt, and pepper",
                    L"Spread cream cheese mixture evenly on each tortilla",
                    L"Layer salami slices to cover the cream cheese",
                    L"Add a layer of spinach leaves",
                    L"Arrange bell pepper slices in a line",
                    L"Roll tortilla tightly from one end",
                    L"Wrap in plastic wrap and refrigerate for 1 hour",
                    L"Slice into 1-inch rounds",
                    L"Arrange on serving platter"
                },
                {
                    L"Use room temperature cream cheese for easier spreading",
                    L"Roll tightly to prevent unraveling",
                    L"Refrigeration helps hold the shape"
                },
                L"Genoa or Milano",
                {L"Pinot Grigio", L"Rosé"}
            }
        };
    }

    std::vector<Models::Recipe> SalamiDatabase::CreateMainCourseRecipes()
    {
        return {
            {
                L"Gourmet Salami Pizza",
                L"Artisan pizza topped with premium salami, fresh mozzarella, and arugula",
                L"Main Course",
                4,
                20,
                15,
                L"Medium",
                {
                    L"1 pizza dough ball (store-bought or homemade)",
                    L"1 cup tomato sauce",
                    L"200g fresh mozzarella, torn into pieces",
                    L"150g salami slices (Milano or Soppressata)",
                    L"2 cups fresh arugula",
                    L"2 tbsp olive oil",
                    L"1 tsp red pepper flakes",
                    L"Fresh basil leaves",
                    L"Balsamic glaze for drizzling",
                    L"Salt and pepper"
                },
                {
                    L"Preheat oven to 475°F (245°C) with pizza stone if available",
                    L"Roll out pizza dough on floured surface to 12-inch diameter",
                    L"Transfer to pizza peel or baking sheet",
                    L"Spread tomato sauce evenly, leaving 1-inch border",
                    L"Distribute mozzarella pieces over sauce",
                    L"Arrange salami slices on top",
                    L"Drizzle with olive oil",
                    L"Bake for 12-15 minutes until crust is golden and cheese is bubbly",
                    L"Remove from oven",
                    L"Top with fresh arugula",
                    L"Drizzle with balsamic glaze",
                    L"Sprinkle with red pepper flakes",
                    L"Garnish with fresh basil",
                    L"Slice and serve immediately"
                },
                {
                    L"Preheat pizza stone for best crust",
                    L"Don't overload with toppings",
                    L"Add arugula after baking to keep it fresh",
                    L"Let pizza rest 2 minutes before slicing"
                },
                L"Milano or Soppressata",
                {L"Chianti", L"Sangiovese", L"Italian Pilsner"}
            },
            {
                L"Salami Carbonara",
                L"Creamy pasta with crispy salami, eggs, and Pecorino Romano",
                L"Main Course",
                4,
                10,
                20,
                L"Medium",
                {
                    L"400g spaghetti or fettuccine",
                    L"150g salami, diced",
                    L"4 large egg yolks",
                    L"1 whole egg",
                    L"100g Pecorino Romano cheese, finely grated",
                    L"2 cloves garlic, minced",
                    L"Black pepper, freshly ground",
                    L"Salt for pasta water",
                    L"Fresh parsley, chopped"
                },
                {
                    L"Bring large pot of salted water to boil",
                    L"Cook pasta according to package directions until al dente",
                    L"Reserve 1.5 cups pasta water before draining",
                    L"While pasta cooks, dice salami into small cubes",
                    L"In a large pan, cook salami over medium heat until crispy (5-7 minutes)",
                    L"Add minced garlic and cook for 1 minute",
                    L"In a bowl, whisk together egg yolks, whole egg, and Pecorino cheese",
                    L"Add generous black pepper to egg mixture",
                    L"When pasta is done, drain and add to pan with salami",
                    L"Remove pan from heat",
                    L"Quickly pour egg mixture over pasta, tossing constantly",
                    L"Add pasta water gradually while tossing to create creamy sauce",
                    L"Continue tossing until sauce coats pasta",
                    L"Season with more black pepper",
                    L"Garnish with parsley and extra Pecorino",
                    L"Serve immediately"
                },
                {
                    L"Remove pan from heat before adding eggs to prevent scrambling",
                    L"Toss constantly for creamy sauce",
                    L"Pasta water helps create silky texture",
                    L"Serve immediately while hot"
                },
                L"Genoa or Felino",
                {L"Vermentino", L"Soave", L"Light red wine"}
            },
            {
                L"Italian Salami Sandwich",
                L"Hearty submarine sandwich loaded with premium salami and Italian ingredients",
                L"Main Course",
                2,
                15,
                0,
                L"Easy",
                {
                    L"1 large ciabatta or baguette",
                    L"100g Genoa salami slices",
                    L"100g Soppressata slices",
                    L"4 slices provolone cheese",
                    L"Lettuce leaves",
                    L"2 tomatoes, sliced",
                    L"1/2 red onion, thinly sliced",
                    L"Pepperoncini peppers",
                    L"3 tbsp olive oil",
                    L"2 tbsp balsamic vinegar",
                    L"1 tsp Italian seasoning",
                    L"Salt and pepper"
                },
                {
                    L"Slice bread lengthwise",
                    L"Lightly toast cut sides of bread",
                    L"Mix olive oil, balsamic vinegar, and Italian seasoning",
                    L"Brush oil mixture on both sides of bread",
                    L"Layer provolone cheese on bottom half",
                    L"Add layers of Genoa salami",
                    L"Add layers of Soppressata",
                    L"Top with lettuce, tomatoes, onion, and pepperoncini",
                    L"Season with salt and pepper",
                    L"Close sandwich and press gently",
                    L"Slice diagonally and serve"
                },
                {
                    L"Toast bread for better texture",
                    L"Let sandwich rest 5 minutes for flavors to meld",
                    L"Wrap tightly for packed lunches"
                },
                L"Genoa and Soppressata",
                {L"Italian red wine", L"Iced tea"}
            },
            {
                L"Salami and White Bean Soup",
                L"Hearty Tuscan-style soup with salami, white beans, and vegetables",
                L"Main Course",
                6,
                15,
                35,
                L"Easy",
                {
                    L"200g salami, diced",
                    L"2 cans (400g each) cannellini beans, drained",
                    L"1 onion, diced",
                    L"3 carrots, diced",
                    L"3 celery stalks, diced",
                    L"4 cloves garlic, minced",
                    L"6 cups chicken broth",
                    L"1 can (400g) diced tomatoes",
                    L"2 cups kale, chopped",
                    L"2 tsp Italian herbs",
                    L"Olive oil",
                    L"Parmesan rind (optional)",
                    L"Fresh parsley",
                    L"Salt and pepper"
                },
                {
                    L"Heat olive oil in large pot over medium heat",
                    L"Add diced salami and cook until crispy",
                    L"Remove salami and set aside, leave fat in pot",
                    L"Add onion, carrots, and celery to pot",
                    L"Sauté vegetables for 5-7 minutes until softened",
                    L"Add garlic and cook for 1 minute",
                    L"Pour in chicken broth and diced tomatoes",
                    L"Add Italian herbs and Parmesan rind if using",
                    L"Bring to a boil, then reduce to simmer",
                    L"Add white beans and simmer for 20 minutes",
                    L"Add chopped kale and cook for 5 minutes",
                    L"Return crispy salami to pot",
                    L"Season with salt and pepper",
                    L"Remove Parmesan rind",
                    L"Serve garnished with fresh parsley and grated Parmesan"
                },
                {
                    L"Salami fat adds wonderful flavor to the soup",
                    L"Can substitute spinach for kale",
                    L"Parmesan rind adds depth of flavor",
                    L"Soup tastes even better the next day"
                },
                L"Genoa or Cacciatore",
                {L"Chianti", L"Montepulciano"}
            }
        };
    }

    std::vector<Models::Recipe> SalamiDatabase::CreateSnackRecipes()
    {
        return {
            {
                L"Salami & Pickle Skewers",
                L"Easy grab-and-go snack skewers with salami, pickles, and cheese",
                L"Snack",
                12,
                10,
                0,
                L"Easy",
                {
                    L"24 salami slices",
                    L"24 cheese cubes (cheddar or mozzarella)",
                    L"24 cherry tomatoes",
                    L"24 pickle slices",
                    L"24 wooden skewers or toothpicks",
                    L"Fresh basil leaves (optional)"
                },
                {
                    L"Fold salami slices in half or quarters",
                    L"Thread one piece of salami onto skewer",
                    L"Add a cheese cube",
                    L"Add a cherry tomato",
                    L"Add a pickle slice",
                    L"Add a basil leaf if using",
                    L"Repeat for all skewers",
                    L"Arrange on serving platter",
                    L"Refrigerate until ready to serve"
                },
                {
                    L"Make ahead and refrigerate up to 4 hours",
                    L"Use colorful cherry tomatoes for visual appeal",
                    L"Perfect for party platters"
                },
                L"Any variety",
                {L"Beer", L"White wine"}
            },
            {
                L"Salami Chips",
                L"Crispy baked salami slices perfect for snacking or garnishing",
                L"Snack",
                4,
                5,
                15,
                L"Easy",
                {
                    L"100g salami slices, thin",
                    L"Black pepper (optional)",
                    L"Paprika (optional)"
                },
                {
                    L"Preheat oven to 375°F (190°C)",
                    L"Line baking sheet with parchment paper",
                    L"Arrange salami slices in single layer",
                    L"Season with black pepper or paprika if desired",
                    L"Bake for 12-15 minutes until crispy",
                    L"Remove and place on paper towels to absorb excess oil",
                    L"Let cool completely before serving",
                    L"Store in airtight container"
                },
                {
                    L"Watch carefully to prevent burning",
                    L"Salami will crisp up more as it cools",
                    L"Great as salad topping or soup garnish"
                },
                L"Milano or Genoa",
                {L"Beer", L"Sparkling water"}
            }
        };
    }

    std::vector<Models::HistoricalEvent> SalamiDatabase::GetHistoricalTimeline()
    {
        std::vector<Models::HistoricalEvent> timeline;
        
        auto ancient = CreateAncientHistory();
        auto medieval = CreateMedievalHistory();
        auto modern = CreateModernHistory();
        
        timeline.insert(timeline.end(), ancient.begin(), ancient.end());
        timeline.insert(timeline.end(), medieval.begin(), medieval.end());
        timeline.insert(timeline.end(), modern.begin(), modern.end());
        
        return timeline;
    }

    std::vector<Models::HistoricalEvent> SalamiDatabase::CreateAncientHistory()
    {
        return {
            {
                L"Ancient Times",
                L"3000 BCE",
                L"Early Meat Preservation",
                L"Ancient civilizations in Mesopotamia and Egypt develop basic meat preservation techniques using salt and drying in the sun.",
                L"Foundation of all future cured meat production",
                L"Middle East"
            },
            {
                L"Ancient Rome",
                L"200 BCE",
                L"Roman Sausage Making",
                L"Romans perfect the art of sausage making, documented in Apicius cookbook. The word 'salami' derives from Latin 'salumen' meaning salted meat.",
                L"Establishment of salami as a refined culinary art",
                L"Roman Empire"
            },
            {
                L"Ancient Greece",
                L"400 BCE",
                L"Greek Curing Methods",
                L"Greek texts describe methods of preserving meat with salt and spices, particularly for long sea voyages.",
                L"Documentation of early curing techniques",
                L"Greece"
            }
        };
    }

    std::vector<Models::HistoricalEvent> SalamiDatabase::CreateMedievalHistory()
    {
        return {
            {
                L"Medieval Era",
                L"1000 CE",
                L"Monastic Production",
                L"European monasteries become centers of salami production, with monks perfecting recipes and documenting techniques.",
                L"Preservation and refinement of traditional methods",
                L"Europe"
            },
            {
                L"Medieval Italy",
                L"1300 CE",
                L"Regional Specialization",
                L"Italian regions develop distinct salami varieties: Genoa uses wine, Milan develops fine-ground methods, and southern regions add hot peppers.",
                L"Birth of regional Italian salami traditions",
                L"Italy"
            },
            {
                L"Medieval Guilds",
                L"1400 CE",
                L"Salami Makers' Guilds",
                L"Formation of professional guilds for salami makers in Italy, establishing quality standards and protecting trade secrets.",
                L"Professionalization of salami production",
                L"Italy"
            }
        };
    }

    std::vector<Models::HistoricalEvent> SalamiDatabase::CreateModernHistory()
    {
        return {
            {
                L"Renaissance",
                L"1500-1600 CE",
                L"Trade and Expansion",
                L"Salami becomes a valuable trade commodity. Italian methods spread throughout Europe via trade routes.",
                L"International spread of salami culture",
                L"Europe"
            },
            {
                L"19th Century",
                L"1850s",
                L"Immigration to Americas",
                L"Italian and German immigrants bring salami-making traditions to North and South America, adapting recipes to local ingredients.",
                L"Globalization of salami production",
                L"Americas"
            },
            {
                L"20th Century",
                L"1920s",
                L"Industrial Production",
                L"First mechanized salami production facilities open, allowing for larger scale production while maintaining traditional methods.",
                L"Modernization of production",
                L"Europe and Americas"
            },
            {
                L"Modern Era",
                L"1990s",
                L"Protected Status",
                L"European Union establishes PDO (Protected Designation of Origin) status for traditional salamis, preserving authentic recipes and methods.",
                L"Legal protection of traditional varieties",
                L"European Union"
            },
            {
                L"21st Century",
                L"2010s",
                L"Artisanal Revival",
                L"Renewed interest in traditional, small-batch salami production. Craft producers emerge worldwide, focusing on quality and heritage methods.",
                L"Renaissance of artisanal production",
                L"Global"
            }
        };
    }

    std::vector<Models::PairingRecommendation> SalamiDatabase::GetPairingRecommendations()
    {
        return {
            {
                L"Genoa Salami",
                {L"Provolone", L"Asiago", L"Fontina"},
                {L"Chianti", L"Pinot Noir", L"Sangiovese"},
                {L"Italian Pilsner", L"Amber Ale"},
                {L"Ciabatta", L"Focaccia", L"Sourdough"},
                {L"Olives", L"Roasted red peppers", L"Fig jam"},
                L"Casual gathering or wine tasting"
            },
            {
                L"Soppressata",
                {L"Pecorino Romano", L"Aged Manchego", L"Gorgonzola"},
                {L"Aglianico", L"Primitivo", L"Zinfandel"},
                {L"IPA", L"Belgian Strong Ale"},
                {L"Rustic Italian bread", L"Cornbread"},
                {L"Hot peppers", L"Honey", L"Pickled vegetables"},
                L"Bold flavor enthusiasts"
            },
            {
                L"Chorizo",
                {L"Manchego", L"Mahón", L"Idiazábal"},
                {L"Rioja", L"Tempranillo", L"Garnacha"},
                {L"Spanish lager", L"Wheat beer"},
                {L"Baguette", L"Pan con tomate"},
                {L"Olives", L"Marcona almonds", L"Quince paste"},
                L"Spanish tapas night"
            },
            {
                L"Milano Salami",
                {L"Mozzarella", L"Fontina", L"Mild provolone"},
                {L"Pinot Grigio", L"Soave", L"Prosecco"},
                {L"Light lager", L"Wheat ale"},
                {L"White bread", L"Crackers"},
                {L"Cherry tomatoes", L"Fresh basil", L"Mild mustard"},
                L"Family-friendly gatherings"
            }
        };
    }

    std::vector<Models::ProductionStep> SalamiDatabase::GetProductionSteps()
    {
        return {
            {
                1,
                L"Meat Selection and Grinding",
                L"Select high-quality pork (and sometimes beef) cuts. Grind meat to desired consistency, from fine to coarse depending on salami variety.",
                L"1-2 hours",
                L"35-40°F (2-4°C)",
                L"N/A",
                {L"Use cold meat for best texture", L"Fat content typically 25-30%", L"Grinder plates determine texture"}
            },
            {
                2,
                L"Mixing and Seasoning",
                L"Combine ground meat with salt, spices, cure (sodium nitrite), and sometimes wine or garlic. Mix thoroughly to distribute seasonings evenly.",
                L"30-45 minutes",
                L"35-40°F (2-4°C)",
                L"N/A",
                {L"Salt content: 2.5-3% of meat weight", L"Cure prevents harmful bacteria", L"Mixing develops protein structure"}
            },
            {
                3,
                L"Stuffing into Casings",
                L"Fill natural or synthetic casings with meat mixture using a sausage stuffer. Remove air pockets to prevent spoilage.",
                L"1-2 hours",
                L"35-40°F (2-4°C)",
                L"N/A",
                {L"Natural casings are traditional", L"Avoid air pockets", L"Tie ends securely"}
            },
            {
                4,
                L"Fermentation",
                L"Hang salamis in temperature-controlled room. Beneficial bacteria convert sugars to lactic acid, lowering pH and developing flavor.",
                L"1-3 days",
                L"65-75°F (18-24°C)",
                L"85-95%",
                {L"pH drops to 4.8-5.2", L"Critical for food safety", L"Flavor development begins"}
            },
            {
                5,
                L"Drying/Aging",
                L"Continue hanging in controlled environment with gradually decreasing temperature and humidity. Moisture evaporates, flavors concentrate.",
                L"3 weeks to 6+ months",
                L"50-60°F (10-15°C)",
                L"70-80% initially, dropping to 60-70%",
                {L"Weight loss: 30-40%", L"White mold may develop (beneficial)", L"Longer aging = more intense flavor"}
            },
            {
                6,
                L"Quality Testing",
                L"Test pH, moisture content, and water activity. Conduct visual inspection and taste testing to ensure quality standards.",
                L"Ongoing",
                L"N/A",
                L"N/A",
                {L"pH should be below 5.3", L"Water activity below 0.92", L"Check for off-odors"}
            },
            {
                7,
                L"Packaging",
                L"Once aged to perfection, salami is packaged whole, sliced, or in portions. Vacuum sealing extends shelf life.",
                L"Varies",
                L"Cold storage",
                L"N/A",
                {L"Vacuum sealing common", L"Some varieties sold with natural mold coating", L"Store in cool, dry place"}
            }
        };
    }

    std::vector<Models::FunFact> SalamiDatabase::GetFunFacts()
    {
        return {
            {
                L"Etymology",
                L"The word 'salami' comes from the Italian 'salare' meaning 'to salt'",
                L"The preservation process relies heavily on salt, which inhibits bacterial growth and draws out moisture.",
                true
            },
            {
                L"World Record",
                L"The longest salami ever made was 1,120 meters long",
                L"Created in 2011 in Hungary, this record-breaking salami required over 1,000 kg of meat.",
                true
            },
            {
                L"Space Food",
                L"Salami has been taken to space on multiple missions",
                L"Its shelf-stable nature and high protein content make it ideal for space travel. Russian cosmonauts particularly favor it.",
                true
            },
            {
                L"White Coating",
                L"The white coating on some salamis is beneficial mold",
                L"Penicillium nalgiovense is deliberately added to protect the salami and contribute to flavor development.",
                true
            },
            {
                L"Ancient Recipe",
                L"Some salami recipes are over 500 years old",
                L"Traditional Italian families pass down salami recipes through generations, some dating back to the Renaissance.",
                true
            },
            {
                L"Economic Impact",
                L"Italy produces over 200,000 tons of salami annually",
                L"The salami industry is a major part of Italy's food economy, worth billions of euros.",
                true
            },
            {
                L"Biodiversity",
                L"There are over 300 varieties of salami worldwide",
                L"Each region has developed unique varieties based on local ingredients, climate, and traditions.",
                true
            },
            {
                L"Aging Process",
                L"Some salamis age for over a year",
                L"Premium salamis like Hungarian salami can age for 6-12 months, developing complex flavors.",
                true
            },
            {
                L"Natural Antibiotics",
                L"The fermentation process produces natural antibiotics",
                L"Lactic acid bacteria create bacteriocins that inhibit harmful microorganisms.",
                true
            },
            {
                L"Temperature Sensitive",
                L"Salami should be stored between 50-60°F for optimal quality",
                L"Too cold and it loses flavor; too warm and it can spoil or become too dry.",
                true
            }
        };
    }

    std::vector<Models::SalamiFestival> SalamiDatabase::GetFestivals()
    {
        return {
            {
                L"Sagra del Salame",
                L"Felino",
                L"Italy",
                L"September",
                L"Annual celebration of Salame Felino with tastings, demonstrations, and cultural events",
                {L"Salami tasting", L"Cooking demonstrations", L"Traditional music", L"Local wine pairings"},
                15000
            },
            {
                L"Festival of Salami",
                L"Sant'Angelo in Vado",
                L"Italy",
                L"October",
                L"Three-day festival celebrating the art of salami making with master salami makers",
                {L"Artisan market", L"Workshops", L"Competitions", L"Street food"},
                20000
            },
            {
                L"Salami Festival",
                L"Csaba",
                L"Hungary",
                L"October",
                L"Celebration of traditional Hungarian salami with international participants",
                {L"Salami competition", L"Cultural performances", L"Food stalls", L"Folk dancing"},
                25000
            },
            {
                L"Chorizo Festival",
                L"Candelario",
                L"Spain",
                L"February",
                L"Annual matanza festival celebrating traditional Spanish salami and chorizo making",
                {L"Traditional slaughter demonstration", L"Chorizo tasting", L"Cooking contest", L"Music"},
                10000
            }
        };
    }
}
