
$( document ).ready(function() {
function mobileslider(){
	
    $('.services-slider').slick({
		slidesToShow: 1,
		slidesToScroll: 1,
        mobileFirst: true,
        arrows: false,
        dots: true,
        responsive: [
            {
                breakpoint: 767,
                settings: 'unslick'
            }
        ]
    });

}

(function(jQuery) {
    $(document).ready(function() {
		
mobileslider();		

	 $('.hero-slider').slick({
	  dots: true,
	  arrows: false,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  speed: 300,
	  slidesToShow: 1,
	  responsive: [
			{
			  breakpoint: 768,
			  settings: {
				dots: false,
			  }
			}
		  ]
	});

	$('.testimonial-slider').slick({
	  dots: true,
	  arrows: false,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  vertical: true,
	  speed: 300,
	  slidesToShow: 1,
	});

	$('.certifications-slider').slick({
	  dots: false,
	  arrows: false,
	  infinite: false,
	  autoplay: false,
	  slidesToShow: 4,
	  responsive: [
		{
		  breakpoint: 768,
		  settings: {
			slidesToShow: 1,
			dots: true,
		  }
		}
	  ]
	});
   $('.patients-slider').slick({
	  dots: false,
	  arrows: true,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  speed: 300,
	  slidesToShow: 2,
	  responsive: [
		{
		  breakpoint: 992,
		  settings: {
			slidesToShow: 1,
		  }
		}
	  ]
	});
	$('.best-testimonials-slider').slick({
	  dots: true,
	  arrows: false,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  speed: 300,
	  slidesToShow: 1,
	});
    $('.what-testi-slider').slick({
	  dots: true,
	  arrows: false,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  speed: 300,
	  slidesToShow: 2,
	  responsive: [
		{
		  breakpoint: 768,
		  settings: {
			slidesToShow: 1,
		  }
		}
	  ]
	});
	$('.today-stories-slider').slick({
	  dots: true,
	  arrows: false,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  vertical: true,
	  speed: 300,
	  slidesToShow: 1,
	});
	$('.libero-volutpat-slider').slick({
	  dots: false,
	  arrows: true,
	  infinite: true,
	  autoplay: true,
	  autoplaySpeed: 2000,
	  speed: 300,
	  slidesToShow: 1,
	});
		
	$(document).ready( function() {

	var itemSelector = '.grid-item'; 

	var $container = $('#container').isotope({
		itemSelector: itemSelector,
		masonry: {
		  columnWidth: itemSelector,
		  isFitWidth: true
		}
	});

	//Ascending order
	var responsiveIsotope = [
		[480, 7],
		[720, 10]
	];

	var itemsPerPageDefault = 12;
	var itemsPerPage = defineItemsPerPage();
	var currentNumberPages = 1;
	var currentPage = 1;
	var currentFilter = '*';
	var filterAtribute = 'data-filter';
	var pageAtribute = 'data-page';
	var pagerClass = 'isotope-pager';

	function changeFilter(selector) {
		$container.isotope({
			filter: selector
		});
	}


	function goToPage(n) {
		currentPage = n;

		var selector = itemSelector;
			selector += ( currentFilter != '*' ) ? '['+filterAtribute+'="'+currentFilter+'"]' : '';
			selector += '['+pageAtribute+'="'+currentPage+'"]';

		changeFilter(selector);
	}

	function defineItemsPerPage() {
		var pages = itemsPerPageDefault;

		for( var i = 0; i < responsiveIsotope.length; i++ ) {
			if( $(window).width() <= responsiveIsotope[i][0] ) {
				pages = responsiveIsotope[i][1];
				break;
			}

			

		}

		return pages;
	}
	
	function setPagination() {

		var SettingsPagesOnItems = function(){

			var itemsLength = $container.children(itemSelector).length;
			
			var pages = Math.ceil(itemsLength / itemsPerPage);
			var item = 1;
			var page = 1;
			var selector = itemSelector;
				selector += ( currentFilter != '*' ) ? '['+filterAtribute+'="'+currentFilter+'"]' : '';
			
			$container.children(selector).each(function(){
				if( item > itemsPerPage ) {
					page++;
					item = 1;
				}
				$(this).attr(pageAtribute, page);
				item++;
			});

			currentNumberPages = page;

		}();

		var CreatePagers = function() {

			var $isotopePager = ( $('.'+pagerClass).length == 0 ) ? $('<div class="'+pagerClass+'"></div>') : $('.'+pagerClass);

			$isotopePager.html('');
			
			for( var i = 0; i < currentNumberPages; i++ ) {
				var $pager = $('<a href="javascript:void(0);" class="pager" '+pageAtribute+'="'+(i+1)+'"></a>');
					$pager.html(i+1);
					
					$pager.click(function(){
						var page = $(this).eq(0).attr(pageAtribute);
						goToPage(page);
					});

				$pager.appendTo($isotopePager);
			}

			$container.after($isotopePager);

		}();

	}

	setPagination();
	goToPage(1);

	//Adicionando Event de Click para as categorias
	$('.filters a').click(function(){
		var filter = $(this).attr(filterAtribute);
		currentFilter = filter;

		setPagination();
		goToPage(1);


	});

	//Evento Responsivo
	$(window).resize(function(){
		itemsPerPage = defineItemsPerPage();
		setPagination();
	});

	

});



 $(document).ready( function() {   

// filter items on button click
$('.filter-button-group').on( 'click', 'li', function() {
  var filterValue = $(this).attr('data-filter');
  $('.grid').isotope({ filter: filterValue });
  $('.filter-button-group li').removeClass('active');
  $(this).addClass('active');
});
    })
	

 $(document).ready( function() {   

// filter items on button click
$('.isotope-pager').on( 'click', 'a', function() {
  var filterValue = $(this).attr('data-page');

  $('.isotope-pager a').removeClass('active');
  $(this).addClass('active');
});
    })
$(".navbar-toggler").click(function(){
  $("body").toggleClass("header-dark");
});		

});
 
$(window).scroll(function(){
  var sticky = $('#HeaderSec'),
      scroll = $(window).scrollTop();

  if (scroll >= 1) sticky.addClass('fixed');
  else sticky.removeClass('fixed');
});

  $(window).on('resize', function() {
        $('.services-slider').slick('resize');
    });

$(function () {
  $(".datepickers").datepicker({ 
        autoclose: true, 
        todayHighlight: true
  }).datepicker('update', new Date());
});
	
})(jQuery);
	
});





